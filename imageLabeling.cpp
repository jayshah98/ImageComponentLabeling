#include <iostream>
#include <queue>
#include <utility>
#include "Pixel.h"

using namespace std;

Pixel** pix;
int size;  // number of rows and columns in the image
float density;
int orderctr = 0;

void inputImage()
{
    cout << "Enter image size" << endl;
    cin >> size;
    if (size < 5 || size > 20){
        size = 15;
    }
    
    cout << "Enter a density for the forground pixels:(between 0,0 and 1.0 " <<endl;
    cin >> density;
    if (density < 0.0 || density > 1.0){
        density = 0.33;
    }
    
    pix = new Pixel*[size];         //created 2d array of objects
    for(int i = 0 ; i < size ; i++)
        pix[i] = new Pixel [size];
    
    
    for (int row = 0; row < size; row++){
        for(int col = 0; col < size; col++)
        {
            float random = 0.0 + (rand() / (RAND_MAX / (1.0)));
            if (random < density)
                pix[row][col].value = 1;
            else
                pix[row][col].value = 0;
            
        }
    }
    
    for (int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
            cout << pix[row][col].value << ' ';
        cout << endl;
    }
}

bool isValid (int row, int col)
{
    return ((row>=0) && (row<size) && (col>=0) && (col<size));
}

void bfs(int row, int col, int val){
    queue<pair<int, int>> Q;
    int ord=1;
    
    int x[] = {0, 0, -1, 1};
    int y[] = {-1, 1, 0, 0};
    Q.push({row, col});
    while (!Q.empty())
    {
        pair<int, int> p;
        p = Q.front();
        Q.pop();
        int u,v;
        u = p.first;
        v = p.second;
        if (pix[u][v].discovered==true)
            continue;
        pix[u][v].discovered = true;
        pix[u][v].label = val;
        pix[u][v].order = ord;
        ord++;
        for (int i=0; i<4; ++i)
        {
            if (isValid(u+x[i], v+y[i]) && pix[u+x[i]][v+y[i]].value==1)
                Q.push({u+x[i], v+y[i]});
        }
    }
    return;
}

void DFS (int row, int col, int val, int &ord)
{
    pix[row][col].discovered = true;
    pix[row][col].label = val;
    pix[row][col].order = ord;
    int x[] = {0, 0, -1, 1};
    int y[] = {-1, 1, 0, 0};
    
    for (int i=0; i<4; ++i)
    {
        if (isValid(row+x[i], col+y[i]) && pix[row+x[i]][col+y[i]].discovered==false && pix[row+x[i]][col+y[i]].value==1)
            DFS(row+x[i], col+y[i], val, ++ord);
    }
    return;
}

void labelComponents()
{
    //arrayQueue<Pixel> que;
    int labelctr = 0;
    
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            
            if (pix[i][j].value == 1 && pix[i][j].discovered==false){
                labelctr++;
                bfs(i, j, labelctr);
            }
        }
    }
    cout <<" BFS SEARCH";
    cout <<endl;
    
    for (int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
            cout <<pix[row][col].label<< "," << pix[row][col].order << ' ';
        cout << endl;
    }
    
    for (int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            pix[row][col].label = 0;
            pix[row][col].discovered = false;
            pix[row][col].order = 0;
        }
    }
    
    cout <<" DFS SEARCH";
    cout <<endl;
    
    labelctr = 0;
    int ord;
    
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            
            if (pix[i][j].value == 1 && pix[i][j].discovered==false){
                labelctr++;
                ord = 1;
                DFS(i, j, labelctr, ord);
            }
        }
    }
    
    for (int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
            cout <<pix[row][col].label<< "," << pix[row][col].order << ' ';
        cout << endl;
    }
    
    
}



int main()
{
    inputImage();
    labelComponents();
}


