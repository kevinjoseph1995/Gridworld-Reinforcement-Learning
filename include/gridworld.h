#ifndef GRIDWORLD_H
#define GRIDWORLD_H

class Gridworld
{   
    private:
    int height=5;
    int width=5;    
    float discount_param = 0.9;
    public:

    struct position
    {
        int x;
        int y;
        void operator=(const position pos)
        {
            x=pos.x;
            y=pos.y;
        }
        bool operator!=(const position pos)
        {
            if (pos.x==x && pos.y==y)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool operator==(const position pos)
        {
            if (pos.x==x && pos.y==y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
    };
    position current_pos;
    Gridworld();
     
    float run_random_policy();
    void select_random_action(int &);
    void perform_action(const int, position&  );
    void system_dynamics(int &action);
    
    
    
};
std::ostream  & operator<<(std::ostream  &,const Gridworld::position pos );
#endif