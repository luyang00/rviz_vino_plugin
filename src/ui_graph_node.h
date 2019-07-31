#ifndef __UI_GRAPH_NODE__H
#define __UI_GRAPH_NODE__H
#include <iostream>
#include <vector>
#include "base_graph_node.h"
namespace vino_pipeline_graph{
    class PipelineEdge: public Edge
    {
    public:
        PipelineEdge(std::string & from, std::string & to) :Edge(from,to){}
    }; 

    class PipelineNode: public Node
    {
    public:
        PipelineNode(std::string node_name): Node(node_name){};
    };

    class PipelineGraph: public Graph
    {
    private:
        Node* createNode(std::string node_name){ return new PipelineNode(node_name);};
    public:
        PipelineGraph(): Graph() {};

    }; 
}
#endif