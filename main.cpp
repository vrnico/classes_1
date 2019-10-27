//Nico Daunt v1.0
#include "main.h"
using namespace std;

int main(int argc, char **argv, char **envp)
{
    req_cs162 required_variable;
    list my_list(argc, argv);
    my_list.set_list(envp);
    my_list.print_list();
    return 0;
}
