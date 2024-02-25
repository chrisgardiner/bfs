/* Chris Gardiner
   1/27/2024
   Big data and cloud computing homework 1
   Breadth first search to traverse a tree 
*/

#include <iostream>
#include <list> //Using lists to keep track of visited and seen nodes
#include <algorithm> //std::find()

class graph
{
    int numVertices;
    std::list< int > *edges;

    public:
        graph(int vertices);
        void addEdge(int source, int destination);
        void bfs(int startVertex);
};

//Constructor for the graph object
graph::graph(int vertices) 
{
    numVertices = vertices;
    edges = new std::list< int >[numVertices];
}

//Add a new edge to the graph
void graph::addEdge(int source, int destination)
{
    edges[source].push_back(destination);
    edges[destination].push_back(source);
}

void graph::bfs(int startVertex)
{
    //Lists for visited and to-be visited vertices
    std::list< int > visited, toVisit;
    toVisit.push_back(startVertex);
    
    //Search until there are no more vertices left to look at
    while(!toVisit.empty())
    {
        int currVertex = toVisit.front();
        //std::cout << "Current Vertex: " << currVertex << std::endl;
        //Remove the now visited from the queue and add it to the visited list
        toVisit.pop_front();
        visited.push_back(currVertex);
        //Find all adjacent edges to the current vertex
        //and add them to the queue
        for(std::list< int >::iterator it = edges[currVertex].begin();
            it != edges[currVertex].end();
            ++it)
        {
            //std::cout << "*it = " << *it << std::endl;
            //Check to make sure this vertex isn't already in one of our lists
            if(std::find(visited.begin(), visited.end(), *it) == visited.end() &&
               std::find(toVisit.begin(), toVisit.end(), *it) == toVisit.end())
            {
                    toVisit.push_back(*it);
            }
        }
    }

    std::cout << "Traversed the graph!";
    for(std::list< int >::iterator it = visited.begin();
        it != visited.end();
        ++it)
    {
        std::cout << " " << *it;
    }
    std::cout << "\n";
}

int main() //Not taking inputs now and just manually constructing the graph
{
    graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    //g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,6);

    g.bfs(1);

    return 0;
}
