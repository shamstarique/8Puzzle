#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

//H_n huerisitic functions for A*
int Misplaced_Tile(vector<vector <int> > puzzle_state){
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

void actual_position(int& val, int& x, int& y)
{
	switch (val) {
	case 1:
		x = 0;
		y = 0;
		break;
	case 2:
		x = 0;
		y = 1;
		break;
	case 3:
		x = 0;
		y = 2;
		break;
	case 4:
		x = 1;
		y = 0;
		break;
	case 5:
		x = 1;
		y = 1;
		break;
	case 6:
		x = 1;
		y = 2;
		break;
	case 7:
		x = 2;
		y = 0;
		break;
	case 8:
		x = 2;
		y = 1;
		break;
	}
};

int Manhattan_Distance(vector<vector <int> > puzzle_state){
    int H_n = 0;
    int act_x, act_y;
    
    for(int i = 0; i < puzzle_state.size(); i++){
       for(int j = 0; j < puzzle_state.at(i).size(); j++){
           if(puzzle_state.at(i).at(j) != 0){
              
               //H_n += abs(   ((puzzle_state.at(i).at(j) - 1) / (puzzle_state.at(i).size())) - i   )  + abs(   ((puzzle_state.at(i).at(j) - 1) % (puzzle_state.at(i).size())) - j   );
               //H_n +=   abs(((puzzle_state.at(i).at(j) - 1) / (puzzle_state.at(i).size())) - i)  +   abs(((puzzle_state.at(i).at(j) - 1) % (puzzle_state.at(i).size())) - j);
                actual_position(puzzle_state.at(i).at(j),act_x,act_y);
                H_n += abs(i-act_x) +abs(j-act_y);
           }
       }
   }
    return H_n;
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

bool Compare_Puzzles(Node a, Node b){
//check if puzzle is same    
    bool puzzles_are_the_same = true;
    for(int i = 0; i < a.puzzle_box.size(); i++){
        for(int j = 0; j < a.puzzle_box.at(i).size(); j++){
            if(a.puzzle_box.at(i).at(j) != b.puzzle_box.at(i).at(j)){
                puzzles_are_the_same = false;
            }
        }
    }
    return puzzles_are_the_same;    
};

void Generate_Next_Nodes(vector< vector<int> > &node_queue, int puzzle_heuristic){
    
    return;
};

void Print_Node(Node a){
    for(int i = 0; i < a.puzzle_box.size(); i++){
        for(int j = 0; j < a.puzzle_box.at(i).size(); j++){
            cout<<a.puzzle_box.at(i).at(j)<<" ";
        }
        cout<<endl;
    }    
    return;
}

int main(){
   
    string string_parse;
    int int_parse;
    int puzzle_form; //should be either 1 or 2 denoting defualt puzzle or their own puzzle
    int puzzle_heuristic;
    //
    int max_nodes_in_queue = 0;
    int goal_node_depth;
    int num_of_expanded_nodes = 0;
    
    
    vector<vector<int> > input_puzzle (3);//TODO: change hardcoding to softcoding hwere size of array can be anything
    vector< vector< vector<int> > > puzzle_list;
    
    vector< vector<int> > default_puzzle (3);
    default_puzzle.at(0).push_back(1);
    default_puzzle.at(0).push_back(2);
    default_puzzle.at(0).push_back(3);
    default_puzzle.at(1).push_back(4);
    default_puzzle.at(1).push_back(0);
    default_puzzle.at(1).push_back(6);
    default_puzzle.at(2).push_back(7);
    default_puzzle.at(2).push_back(5);
    default_puzzle.at(2).push_back(8);
    
    priority_queue<Node, vector<Node>, Compare_Nodes> node_queue;
    /*
    node_queue.push(Node(input_puzzle,1,4));
    node_queue.push(Node(input_puzzle,0,0));
    node_queue.push(Node(input_puzzle,1,3));
    
    Node z = node_queue.top();
    cout<<"top of queue:"<<z.G_n + z.H_n<<endl;
    node_queue.pop();
    z = node_queue.top();
    cout<<"top of queue after pop:"<<z.G_n + z.H_n<<endl;
    node_queue.pop();
    z = node_queue.top();
    cout<<"top of queue after 2nd pop:"<<z.G_n + z.H_n<<endl;
    */

    //Generating interface and Collecting Input from User
    //TODO: sanitize and error check input
    cout<<"Welcome to Khuaja Shams's 8-puzzle solver.\n";
    cout<<"Type "<<1<<" to use a default puzzle, or "<<2<<" to enter your own puzzle.\n";
    getline(cin,string_parse);
    stringstream(string_parse) >> puzzle_form; 
   
    if(puzzle_form == 2){
        
        cout<<"\tEnter your puzzle, use a zero to represent the blank\n";
        
        cout<<"\tEnter the first row, use space or tabs between numbers\t\t";
        //TODO: put this iterative sequence in a loop to make it the puzzle is expandable in size
        getline(cin,string_parse);
        stringstream ss1(string_parse); //TODO: figure out how to use 1 stringstream instance
        while(ss1>>int_parse){
            input_puzzle.at(0).push_back(int_parse);
        }
        
        cout<<"\tEnter the second row, use space or tabs between numbers\t\t";
        getline(cin,string_parse);
        stringstream ss(string_parse); 
        while(ss>>int_parse){
            input_puzzle.at(1).push_back(int_parse);
        }
        
        cout<<"\tEnter the third row, use space or tabs between numbers\t\t";
        getline(cin,string_parse);
        stringstream ss2(string_parse); 
        while(ss2>>int_parse){
            input_puzzle.at(2).push_back(int_parse);
        }
    }
    
    cout<<"\n\tEnter your choice of algorithm"; 
    cout<<"\n\t1. Uniform Cost Search.";
    cout<<"\n\t2. A* with the Misplaced Tile heurisitic.";
    cout<<"\n\t3. A* with the manhattan distance heuristic.\n";
    getline(cin,string_parse);
    stringstream(string_parse) >> puzzle_heuristic; 
    
    cout<<"\nExpanding State\n\n";
    Node given_puzzle = Node(default_puzzle, 0 ,0);
    

    if(puzzle_heuristic == 1){
        given_puzzle = Node(default_puzzle,0,0);
    }else if(puzzle_heuristic == 2){
        given_puzzle = Node(input_puzzle,0,Misplaced_Tile(input_puzzle));
    }else if(puzzle_heuristic == 3){
        given_puzzle =Node(input_puzzle,0,Manhattan_Distance(input_puzzle));
    }else{
        cout<<"ERROR: PLEASE ENTER A VALID HEURISTIC. ACCPETABLE INPUT ARE 1 , 2, and 3."<<endl;
    }
    
    Print_Node(given_puzzle);
    node_queue.push(given_puzzle);
    cout<<"done";
    //while(!node_queue.empty()){
        
    //}
    
    /*
    cout<<"puzzle input"<<endl;
    for(int i = 0; i <input_puzzle.size(); i++){
        for(int j = 0; j < input_puzzle.at(0).size(); j++){
            cout<<input_puzzle.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    
    cout<<"default puzzle"<<endl;
    for(int i = 0; i <default_puzzle.size(); i++){
        for(int j = 0; j < default_puzzle.at(0).size(); j++){
            cout<<default_puzzle.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    
    
    cout<<"manhattan distance of default puzzle: "<<Manhattan_Distance(default_puzzle)<<endl;
    */
//TODO: print expanded manhattan 
    return 0;
}