#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

//H_n huerisitic functions for A*
int Misplaced_Tile_H(vector<vector <int> > puzzle_state){
   int H_n = 0;//H(n) value to be plugged into f(n) = H(n) + g(n)
   for(int i = 0; i < puzzle_state.size(); i++){
       for(int j = 0; j < puzzle_state.at(i).size(); j++){
           if((i*puzzle_state.size() + j + 1) != puzzle_state.at(i).at(j)){
               H_n++;
           }
       }
   }
   return H_n; 
};

int Manhattan_Distance(vector<vector <int> > puzzle_state){
    int H_n = 0;
    for(int i = 0; i < puzzle_state.size(); i++){
       for(int j = 0; j < puzzle_state.at(i).size(); j++){
           H_n += 0;
       }
   }
    return H_n;
};


void Generate_Next_Nodes(){
    
    return;
};

//Node struct and node comparison for the Priority Queue
struct Node{
    vector <vector <int> > puzzle_box;
    int G_n;//g(n) is effectively the depth
    int H_n;//H(n) is iether 1, manhatan distance or mispalce tile huerisitcs
    
    Node(vector <vector <int> > puzzle_box, int G_n, int H_n): puzzle_box(puzzle_box), G_n(G_n), H_n(H_n){
    }
};

struct Compare_Nodes{
    bool operator()(Node const &a, Node const &b){
        return (a.G_n + a.H_n) >  (b.G_n + b.H_n);
    }
};

int main(){
    
    int puzzle_form; //should be either 1 or 2 denoting defualt puzzle or their own puzzle
    
    //
    int max_nodes_in_queue = 0;
    int goal_node_depth;
    int num_of_expanded_nodes = 0;
    
    
    vector<vector<int> > puzzle1;
    vector<int> a(3);
    vector<int> b(3);
    vector<int> c(3);
    
    cout<<"a0:"<<a.at(0);
    puzzle1.push_back(a);
    puzzle1.push_back(b);
    puzzle1.push_back(c);
    
    
    
    priority_queue<Node, vector<Node>, Compare_Nodes> queue;
    
    queue.push(Node(puzzle1,1,1));
    queue.push(Node(puzzle1,0,0));
    queue.push(Node(puzzle1,1,1));
    
    Node z = queue.top();
    cout<<"top of queue:"<<z.G_n + z.H_n<<endl;
    queue.pop();
    z = queue.top();
    cout<<"top of queue after pop:"<<z.G_n + z.H_n<<endl;
    queue.pop();
    z = queue.top();
    cout<<"top of queue after 2nd pop:"<<z.G_n + z.H_n<<endl;
/*
    //Generating interface and Collecting Input from User
    cout<<"Welcome to Khuaja Shams's 8-puzzle solver.\n";
    cout<<"Type "1" to use a default puzzle, or "2" to enter your own puzzle\n.
    cin>>puzzle_form; //TODO: sanitize and error check input
    //TODO:grab userinput
    cout<<"Enter your puzzle, use a zero to represent the blank\n";
    cout<<"Enter the first row, use space or tabs between numbers";
    //TODO: grab first row
    cout<<"\nEnter the second row, use space or tabs between numbers";
    //TODO: grab 2nd row
    cout<<"\nEnter the third row, use space or tabs between numbers";
    cout<<"\n\nEnter your choice of algorithm";
    cout<<"\n1. Uniform Cost Search.";
    cout<<"\n2. A* with the Misplaced Tile heurisitic.";
    cout<<"\n3. A* with the manhattan distance heuristic.";
*/
//TODO: print expanded manhattan 
    return 0;
}