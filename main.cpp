
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    char data;
    Node *next;
    Node(char d){
        this->data = d;
        next = NULL;
    }
    Node(){
        this->data = ' ';
        next = NULL;
    }
    
    void insert(char d){
        if(data == ' '){
            data = d;
        }else if(next == NULL){
            next = new Node(d);
        }else{
            next->insert(d);
        }
    }

    string returnString(string input){
        input = input + string(1,data);
        if(next == NULL){
            return input;
        }else{
            return next->returnString(input);
        }
    }

};

    
string convert(string s, int numRows) {
    string builder = "" ;
    
    if(numRows == 1){
        return s;
    }
    if(s.length() <= numRows){
        return s;
    }
    
    std::vector<Node*> list(numRows);
    
    bool down = true;
    
    int counter = 0;
    
    for(int i = 0; i < s.length(); ++i){
        if(list[counter] == NULL){
            list[counter] = new Node(s[i]);
        }else{
            list[counter]->insert(s[i]);
        }
        
        if(down) {
            ++counter;
        }else{
            --counter;
        }
        if(counter == numRows){
            down = false;
            counter = counter -2;
        }else if(counter == -1){
            down = true;
            counter = 1;
        }
    }
    
    
    for(int i = 0; i < numRows; ++i){
        
        if(list[i]){
            builder += list[i]->returnString("");
            cout<<endl;
        }
    }
    
    return builder;
}

    
int main(int argc, char **argv)
{
	cout<<"Zig Zag"<<endl;
    string test1 = "PAYPALISHIRING";
    cout<<convert(test1,3)<<endl;;
    
    return 0;
    
}
