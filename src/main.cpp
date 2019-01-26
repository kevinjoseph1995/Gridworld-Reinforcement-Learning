#include<iostream>
#include "gridworld.h"
#include<thread>

int main()
{
    Gridworld g;
    std::cout<<g.run_random_policy()<<std::endl;   
    
    
}