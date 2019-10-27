#include <iostream>
#include <string>

class     list
{
     public:
          list();
          list(const list &);
          list(int, char**);
          ~list();
          void          print_list() const;
          void          set_list(char **);

     private:
          std::string    data[1000];
          int            size;
          int            capacity;
};
