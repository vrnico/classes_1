/*
Classes_1 Assignment CS 162
Program returns a list of command line arguments
and environment variables in ASCII order
*/
#include "list.h"

using namespace std;
//iterate through list using default constructor
list::list()
{
     size = 0;
     capacity = 1000;

     for(int idx = 0; idx < capacity; idx++){
          data[idx] = "";
     }
}
//copy constructor sets variables equal to other_list 
list::list(const list& other_list)
{
     size = other_list.size;
     capacity = other_list.capacity;

     for(int idx = 0; idx < capacity; idx++){
          data[idx] = other_list.data[idx];
     }
}
//print list is the accesor and displays list to the cout stream
void list::print_list() const
{
     for(int idx = 0; idx < size; idx++){
          std::cout << data[idx] << std::endl;
     }
}
//paramaterized constructor ensures list is in correct pos and  ASCII order
list::list(int argc, char** args)
{
     size = 0;
     capacity = 1000;

     for(int idx = 0; idx < capacity; idx++){
          data[idx] = "";
     }

     std::string buffer;

     for(int idx_2 = 0; idx_2 < argc; idx_2++){
          buffer = std::string(args[idx_2]);
          if (size == 0){
               data[size++] = buffer;
          }

          char found = 'n';
          int marker = 0;

          for(marker = 0; marker < size; marker++){
               if (buffer == data[marker]){
                    found = 'y';
                    break;
               }
               if(data[marker] > buffer){
                    found = 'n';
                    break;
               }
          }
          if (found == 'n'){
               for(int slide = size; slide > marker; slide--){
                    data[slide] = data[slide - 1];
               }
          data[marker] = buffer;
          size++;
          }
     }
}
//set list is the mutator with envp sentinel array
void list::set_list(char** envs)
{
     std::string env_string;

     for(int idx_3 = 0; envs[idx_3] != 0; idx_3++){
          env_string = std::string(envs[idx_3]);

          char in_list = 'n';
          int pos = 0;

          for(pos = 0; pos < size; pos++){
               if(env_string == data[pos]){
                    in_list = 'y';
                    break;
               }
               if (data[pos] > env_string){
                    in_list = 'n';
                    break;
               }
          }
          if (in_list == 'n'){
               for(int slide = size; slide > pos; slide--){
                    data[slide] = data[slide -1];
               }
          data[pos] = env_string;
          size++;
          }
     }
}

//destructor
list::~list()
{
size =0;
}

