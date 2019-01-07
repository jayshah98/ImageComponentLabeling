#include <iostream>
#include "Pixel.h"

using namespace std;

    Pixel::Pixel(){
        label = 0;
        order = 0;
        value = 0;
        discovered = false;
        
        
    }
    void Pixel::setLabel(int lab){
        label = lab;
    }
    
    void Pixel::setVal(int val){
        value = val;
    }
    

    void Pixel::setOrder(int ord){
        order = ord;
    }
    
    void Pixel:: setDiscovered(){
    discovered = true;
    }



