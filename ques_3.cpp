/*
student name : Tania Chowdhury
Course name : CSCI 313
Professor name : Matthew Fried

EXTRA CREDIT
*/
#include<climits>
#include<iostream>
using namespace std;
void findLongestPath(int**edges,int n,int N_1,int N_2)
{
    int *visited=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;//The visited array which stores if a node is visited or Not.
    }
    int *distance=new int[n];
    //Taken N_1 as source vertex
    distance[N_1]=0;
    for(int i=0;i<n;i++)
    {
        if(i==N_1)
        {
            continue;
        }
        distance[i]=INT_MIN;
    }
    int maxdistance=INT_MIN;
    //Index will have the index of MAX distance.
    int index;
    //Run the code for every Node
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            //Finding the vertex with max distance from all the unvisted vertex.
            if(visited[i]==0&&distance[i]>maxdistance)
            {
                maxdistance=distance[i];
                index=i;
            }
        }
        visited[index]=1;
        //Exploring its neighbours which are unvisited
        for(int i=0;i<n;i++)
        {
            if(edges[index][i]!=0&&visited[i]==0)
            {
                if(distance[index]+edges[index][i]>distance[i])
                {
                    distance[i]=distance[index]+edges[index][i];
                }
            }
        }
        maxdistance=INT_MIN;
    }
    cout<<"The longest distance of "<<N_2<<" from "<<N_1<<" is "<<distance[N_2];
}

int main()
{
    int n,e;//n Number of Nodes,e number of edges
    cin>>n>>e;
    int sv,ev,wei;//starting vertex,ending vertex,weight
    int **edges=new int*[n];//Creating an adjacency Matrix
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;//Initially all nodes given 0 weights
        }
    }
    for(int i=0;i<e;i++)
    {
        cin>>sv>>ev>>wei;
        edges[sv][ev]=wei;//As a directed graph
    }
    int N_1,N_2;//Chosen Nodes
    cin>>N_1>>N_2;
    findLongestPath(edges,n,N_1,N_2);
}