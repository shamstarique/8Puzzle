#include<iostream>
#include<string>

using namespace std;

//misplaced tile huerisitic function for A*
int Misplaced_Tile_H(vector<vector <int>> puzzle_state){
   int H_n = 0;//H(n) value to be pulgged into f(n) = H(n) + g(n)
   for(int i = 0; i < puzzle_state.size(); i++){
       for(int j = 0; j < puzzle_state.at(i).size(); j++){
           if((i*puzzle_state.size() + j + 1) != puzzle_state.at(i).at(j)){
               H_n++;
           }
       }
   }
   return H_n; 
}

int Manhattan_Distance(vector<vector <int>> puzzle_state){
    int H_n = 0;
    for(int i = 0; i < puzzle_state.size(); i++){
       for(int j = 0; j < puzzle_state.at(i).size(); j++){
           value = 
       }
   }
    return H_n;
}

void generate_next_nodes(){
    
    return;
}

int main(){
    
    int puzzle_form; //should be either 1 or 2 denoting defualt puzzle or their own puzzle
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
    cout<<"\n1.Uniform Cost Search.";
    cout<<"\n2.A* with the Misplaced Tile heurisitic.";
    cout<<"\n3. A* with the manhattan distance heuristic."

//TODO: print expanded manhattan 
    return 0;
}