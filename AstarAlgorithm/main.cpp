#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

#define ROW 5
#define COL 5

typedef std::pair<int,int> Pair;
typedef std::pair< double, std::pair<int,int> > pPair;

struct cell
{
    int parent_i, parent_j;
    double f,g,h;
    int x,y;
};

// Map에서 1인지 0인지 확인
bool isAvailable(Pair node, int grid[ROW][COL])
{
    bool avail;

    if(grid[node.first][node.second] == 1)
    {
        avail = true;
        return avail;
    }
    else
    {
        avail = false;
        return avail;
    }
};

bool isNode(Pair node)
{
    bool right;

    if(node.first >=0 && node.second >=0 )
    {
        right = true;
        return right;
    }
    else
    {
        right = false;
        return right;
    }
}

void showMap(int grid[ROW][COL])
{
    int i,j;

    std::cout << "The Map is : " << std::endl;
    for (i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(j == 0)
            {
                std::cout << "| ";
            }
            std::cout << grid[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "\n";
}

bool isArrived(Pair next_node, Pair goal)
{
    bool isArrived = true;

    if(next_node.first == goal.first && next_node.second == goal.second)
    {
        isArrived = true;
    }
    else
    {
        isArrived = false;
    }
    return isArrived;
}

double EuclideanDistance(Pair node, Pair start, Pair goal)
{
    cell distance;

    distance.x = abs(node.first - start.first);
//    std::cout << distance.x << std::endl;
    distance.y = abs(node.second - start.second);
//    std::cout << distance.y << std::endl;
    distance.g = sqrt(pow(distance.x,2) + pow(distance.y, 2));
//    std::cout << " The cost 'g' is : " << distance.g << std::endl;

    distance.x = 0;
    distance.y = 0;
    distance.x = goal.first - node.first;
//    std::cout << distance.x << std::endl;
    distance.y = goal.second - node.second;
//    std::cout << distance.y << std::endl;
    distance.h = sqrt(pow(distance.x,2) + pow(distance.y, 2));
//    std::cout << " The cost 'h' is : " << distance.h << std::endl;

    distance.f = distance.g + distance.h;
//    std::cout << " The cost 'f' is : " << distance.f << std::endl;


    return distance.f ;
}

void AstarAlgorithm(Pair start, Pair goal, int grid[ROW][COL])
{
    showMap(grid);

    std::set<pPair> openList;
    std::set<Pair> closedList;

    std::stack<Pair> Path;

    cell next;
    Pair prev_node;

    prev_node.first = start.first;
    prev_node.second = start.first;

    closedList.insert(std::make_pair(start.first,start.second));

    next.parent_i = prev_node.first;
    next.parent_j = prev_node.second;

    next.x = start.first;
    next.y = start.second;

    Pair chosen_node;
    Pair test_node;

    for (int i =0; i<10; i++)
    {
        std::cout << "iteration " << i << std::endl;
        next.g = FLT_MAX;
        next.h = FLT_MAX;
        next.f = FLT_MAX;

        // North

        test_node = std::make_pair(next.x,next.y-1);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;
            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // South

        test_node = std::make_pair(next.x,next.y+1);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {
                    }
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }


                }

                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;

            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // West

        test_node = std::make_pair(next.x-1,next.y);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f && test_node.first != next.parent_i && test_node.second != next.parent_j)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;

            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // East

        test_node = std::make_pair(next.x+1,next.y);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f && test_node.first != next.parent_i && test_node.second != next.parent_j)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;


            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // North-East

        test_node = std::make_pair(next.x+1,next.y-1);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f && test_node.first != next.parent_i && test_node.second != next.parent_j)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;

            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // North-West

        test_node = std::make_pair(next.x-1,next.y-1);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f && test_node.first != next.parent_i && test_node.second != next.parent_j)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;
            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // South-East

        test_node = std::make_pair(next.x+1,next.y+1);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f && test_node.first != next.parent_i && test_node.second != next.parent_j)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }

                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;

            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        // South-West

        test_node = std::make_pair(next.x,next.y-1);
        if (isNode(test_node) )
        {
            if(isAvailable(test_node,grid))
            {
                if(EuclideanDistance(test_node, start, goal) < next.f && test_node.first != next.parent_i && test_node.second != next.parent_j)
                {
                    if(test_node.first == next.parent_i && test_node.second == next.parent_j)
                    {}
                    else
                    {
                        chosen_node = test_node;
                        next.f = EuclideanDistance(test_node, start, goal);
                        openList.insert(std::make_pair(next.f,std::make_pair(next.x,next.y)));
                    }
                }

                std::cout << "(" << test_node.first << ',' << test_node.second << ") : Available !" << std::endl;
                std::cout << "Chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;
                std::cout << "Cost : " << next.f << std::endl;
            }
            else
            {
                std::cout << "(" << test_node.first << ',' << test_node.second << ") : not Available !" << std::endl;
            }
        }
        else
        {
            std::cout << "(" << test_node.first << ',' << test_node.second << ") : not a node !" << std::endl;
        }

        std::cout << "* Final chosen node : " << chosen_node.first << " " << chosen_node.second << std::endl;

        if(chosen_node.first == goal.first && chosen_node.second == goal.second)
        {
            std::cout << "We arrived at the destination." << std::endl;
            break;
        }
        next.parent_i = prev_node.first;
        next.parent_j = prev_node.second;

        Path.push(std::make_pair(chosen_node.first, chosen_node.second));
        std::cout << "parent_i : " << next.parent_i << std::endl;
        std::cout << "parent_j : " << next.parent_j << std::endl;
        std::cout << "\n";

        prev_node.first = chosen_node.first;
        prev_node.second = chosen_node.second;

        next.x = chosen_node.first;
        next.y = chosen_node.second;

        test_node.first = next.x;
        test_node.second = next.y;

    }
    printf("\nThe Path is ");

    printf("(%d,%d)", goal.first,goal.second);
    while (!Path.empty())
    {
        std::pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }
    printf("-> (%d,%d)", start.first,start.second);

    return ;

}

int main()
{
    Pair start,goal;

    start = std::make_pair(0,0);
    goal = std::make_pair(4,4);
//    test = std::make_pair(1,0);

    int grid[ROW][COL] =
            {
                    {1,1,1, 1, 1},
                    {1,0,1, 1, 1},
                    {1,0,1, 1, 1},
                    {1,1,0, 0, 1},
                    {1,1,1, 1, 1}
            };

    AstarAlgorithm(start,goal,grid);
}

// 1. 내가 갈 수 있는 노드인지 확인하기 => 벽인지 아닌지 확인 해야 함 !!