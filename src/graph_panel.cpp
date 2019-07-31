#include <iostream>
#include <math.h>

#include <QPainter>
#include <QMouseEvent>

#include "graph_panel.h"
#include "base_graph_node.h"
#include "ui_graph_node.h"

namespace vino_pipeline_graph
{

PipelinePaintWidget::PipelinePaintWidget( QFrame* parent )
  : QFrame( parent )
{
    // this->resize(400,566);
    QPalette   palette;
    palette.setBrush(QPalette::Window, QBrush(Qt::red));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    PipelineGraph graph;
    graph.makeRoot("StandardCamera");
    graph.makeConnection("StandardCamera","ObjectDetection");
    graph.makeConnection("ObjectDetection","ImageWindow");
    graph.makeConnection("ObjectDetection","Rviz");
    graph.makeConnection("ObjectDetection","Rostopic");
    graph.makeConnection("ObjectDetection","FaceDetection");
    graph.makeConnection("FaceDetection","Face Re-ID");
    graph.makeConnection("Face Re-ID","ImageWindow");
    graph.makeConnection("FaceDetection","ImageWindow");
    graph.makeConnection("FaceDetection","Tracking");
    graph.makeConnection("Tracking","Rviz");
    graph.printAllNodes();
    graph.printAllEdges();
    graph.printIsolatedNodes();
    
    std::cout << "Max depth: " << graph.getMaxDepth() << std::endl;
    std::cout << "Max width: " << graph.getMaxWidth() << std::endl;
    
    graph.removeConnection("ObjectDetection","FaceDetection");
    graph.removeNode("FaceDetection");
    graph.printAllEdges();
    graph.printAllEdges();
    graph.printIsolatedNodes();


    // graph.makeNode("Vehicle Detection");
    // graph.makeNode("ImageWindow");
    // graph.makeNode("Emotion Detection");
    // graph.makeNode("Vehicle Detection");
    // graph.printIsolatedNodes();

    // graph.makeConnection("Face Re-ID","Emotion Detection");
    // graph.makeConnection("Emotion Detection", "ImageWindow");

    // graph.printAllNodes();
    // graph.printIsolatedNodes();
    // graph.printAllEdges();
    // std::cout << "remove object detection and face detecion connection...." << std::endl;
    // graph.removeConnection("Emotion Detection","ImageWindow");
    // graph.printAllNodes();
    // graph.printIsolatedNodes();
    // graph.printAllEdges();


    


   
    
}

// This paintEvent() is complex because of the drawing of the two
// arc-arrows representing wheel motion.  It is not particularly
// relevant to learning how to make an RViz plugin, so I will kind of
// skim it.
void PipelinePaintWidget::paintEvent( QPaintEvent* event )
{
    QSize window_size = this->size();
    if(window_size.width()<50 || window_size.height()<200){
        QPainter painter(this);
        painter.setPen(Qt::blue);
        painter.drawText(5,5,"Resize to view it.");
    }
}
void PipelinePaintWidget::resizeEvent(QResizeEvent * event)
{
    // QSize window_size = event->size();
    // if(window_size.width()<50 || window_size.height()<200){
    //     QPainter painter(this);
    //     painter.setPen(Qt::blue);
    //     painter.drawText(5,5,"Resize to view it.");
    // }
}


} // end namespace rviz_plugin_tutorials
