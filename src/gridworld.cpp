#include<iostream>
#include "gridworld.h"
#include<cstdlib>
#include<ctime>
#include<cmath>

Gridworld::Gridworld()
{
    std::cout<<"Gridworld Initialized"<<std::endl;
    Gridworld::current_pos.x=0;
    Gridworld::current_pos.y=0;


}

void Gridworld::select_random_action(int & action)
{

    action= std::rand() % 4;     

}

void Gridworld::system_dynamics(int &action)
{
    float p = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
    int dynamics;
    if (p<0.8)
    {
        dynamics=0;//Move in intended direction
    }
    if (p>=0.8 && p<0.85)
    {
        dynamics=1;//Veer Left
    }
    if (p>=0.85 && p<0.9)
    {
        dynamics=2;//Veer Right
    }
    if (p>=0.9)
    {
        dynamics=2;//Stay put
    }
    switch (action)
    {
        case 0:
            switch (dynamics)
            {
                
                case 1:
                    action=3;
                    break;
                case 2:
                    action=1;
                    break;
                case 3:
                    action=4;
                    break;
            
                default:
                    break;
            }
            break;
            
        case 1:
            switch (dynamics)
            {
                
                case 1:
                    action=0;
                    break;
                case 2:
                    action=2;
                    break;
                case 3:
                    action=4;
                    break;
            
                default:
                    break;
            }
            break; 
        case 2: 
            switch (dynamics)
            {
                
                case 1:
                    action=1;
                    break;
                case 2:
                    action=3;
                    break;
                case 3:
                    action=4;
                    break;
            
                default:
                    break;
            }
            break;
        case 3: 
            switch (dynamics)
            {
                
                case 1:
                    action=0;
                    break;
                case 2:
                    action=2;
                    break;
                case 3:
                    action=4;
                    break;
            
                default:
                    break;
            }
            break;
        default:
            std::cout<<"Wrong Action Input";
    }
    
}

void Gridworld::perform_action(const int action,Gridworld::position & next_pos)
{    
    int temp;
    position obstacle1={2,2};
    position obstacle2={3,2};

    switch (action)
    {
        case 0:
            temp=this->current_pos.x-1;
            if (temp>=0)
            {
                position temp_1;
                temp_1.x=temp;
                temp_1.y=this->current_pos.y;
                if (temp_1!=obstacle1 && temp_1!=obstacle2)
                {
                    next_pos=temp_1;
                }
                else
                {
                    next_pos=this->current_pos;
                }

            }
            else
            {
                next_pos=this->current_pos;
                
            }         
            
            break;
        case 1:
            temp=this->current_pos.y+1;
            if (temp < this->width)
            {
                position temp_1={this->current_pos.x,temp};                
                if (temp_1!=obstacle1 && temp_1!=obstacle2)
                {
                    next_pos=temp_1;
                }
                else
                {
                    next_pos=this->current_pos;
                }

            }
            else
            {
                next_pos=this->current_pos;
                
            }
            break;
        case 2:
            temp=this->current_pos.x+1;
            if (temp < this->height)
            {
                position temp_1;
                temp_1.x=temp;
                temp_1.y=this->current_pos.y;
                if (temp_1!=obstacle1 && temp_1!=obstacle2)
                {
                    next_pos=temp_1;
                }
                else
                {
                    next_pos=this->current_pos;
                }

            }
            else
            {
                next_pos=this->current_pos;
                
            } 
            break;
        case 3:
            temp=this->current_pos.y-1;            
            if (temp >=0)
            {
                
                position temp_1={this->current_pos.x,temp};                    
                if (temp_1!=obstacle1 && temp_1!=obstacle2)
                {
                    next_pos=temp_1;
                }
                else
                {
                    next_pos=this->current_pos;
                }

            }
            else
            {
                next_pos=this->current_pos;
                
            }
            break;
        case 4:
            next_pos=this->current_pos;
            break;
    
        default:
            break;
    }

}
std::ostream  & operator<<(std::ostream  &,const Gridworld::position pos )
{
            std::cout<<"("<<pos.x<<','<<pos.y<<')';
}

float Gridworld::run_random_policy(){
    
    int action;
    Gridworld::position next_pos;
    Gridworld::position final_position={4,4};//Final Terminal State
    Gridworld::position water_position={4,2};//Final Terminal State
    // Use current time as seed for random generator 
    std::srand(std::time(0));
    //MESSAGE
    std::cout<<"Random Policy Running"<<std::endl;
    //Initialze Reward
    float r = 0.0;
    //Initialize time-step
    int t=0;
    while(1)
    {        
        // Select action based on random policy
        Gridworld::select_random_action(action);
        //Attempt random action        
        Gridworld::system_dynamics(action);
        Gridworld::perform_action(action, next_pos);        
        this->current_pos=next_pos;        
        if (this->current_pos==final_position)
        {
            r+=std::pow(this->discount_param,t)*10.0;
            return r;            
        }
        if (this->current_pos==water_position)
        {
            r+=std::pow(this->discount_param,t)*-10.0;
            
        }
        t+=1;
        
    }
}