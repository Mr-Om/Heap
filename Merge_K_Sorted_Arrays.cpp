#include<bits/stdc++.h>
using namespace std;

class myComp { 
    public:
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) 
    { 
        return a.second > b.second; 
    } 
}; 

vector<int> merge(vector<vector<int> > v, int k)
{
    vector<int> result;

    priority_queue<pair<int, int>, vector<pair<int,int>> , myComp> pq; // heap of size k ordered by second element
    // 1st element of pair is id 2nd will be data
    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(i,v[i][0]));
    }

    while(pq.top().second!=INT_MAX)
    {
        result.push_back(pq.top().second);
        int front = pq.top().first;
        v[front].erase(v[front].begin());
        
        pq.pop();

        if(!v[front].empty())
            pq.push(make_pair(front,v[front][0]));
        else
            pq.push(make_pair(front,INT_MAX));

    }

    return result;
}

int main()
{
    vector<vector<int> > store;
    int k; // No of arrays to be merged
    cin>>k;

    for(int i=0;i<k;i++)
    {
        int size;
        cin>>size;
        vector<int> temp;
        for(int j=0;j<size;j++)
        {
            int element_at_j;
            cin>>element_at_j;
            temp.push_back(element_at_j);
        }
        store.push_back(temp);
    }
    vector<int> merged_array = merge(store,k);

    for(int i=0;i<merged_array.size();i++)
    {
        cout<<merged_array[i]<<" ";
    }
}