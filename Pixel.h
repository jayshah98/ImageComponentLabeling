
#ifndef pixel_
#define pixel_

#include <iostream>

using namespace std;

class Pixel{
    
    public:
    int label;
    int order;
    int value;
    bool discovered;
    bool connected;

        Pixel();
        
        void setLabel(int lab);
    
        void setVal(int val);

        void setOrder(int ord);

        void setDiscovered();
    
        void setConnected();

};

#endif
