#include <iostream> 
#include <fstream>
using namespace std;    

int l = 100;
int c = 200; 

int fire[160000];

void create_basefire (){
    for  (int i = (l * c - c); i < (l * c); i++ ){
        fire[i] = 36;
    }
}

int decrement (int top_range){
    return rand() % top_range;
}
void update_fire () { 
    for (int i = 0; i < (l * c - c); i++){
        int updated = fire[i + c + decrement(3)] - decrement(3); 
        if (updated > 0){
            fire[i] = updated;      
        }
    }
}

void show_fire(){
    cout << endl;
    for ( int i=0; i < (l * c); i++ ){
        if( i % c == 0 ){
            cout << endl;
        }
        cout << fire[i] << " ";
    }
}

void write_array(){
    ofstream myfile;
    myfile.open ("teste.txt");
    
    for ( int i=0; i < (l * c); i++ ){
        if( (i % c == 0) && (i != 0) ){
            myfile << "\n";
        }
        myfile << fire[i] << ";";
    }

    myfile.close();
     
}

int main(){

    srand(time(NULL));
    create_basefire(); 
    
    for (int i = 0; i < l; i ++){
        show_fire(); 
        update_fire();
    }
    write_array();

    return 0;
}

