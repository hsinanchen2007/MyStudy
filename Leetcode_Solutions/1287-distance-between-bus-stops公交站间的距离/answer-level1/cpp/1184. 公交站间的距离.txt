出这么简单的题真的好么……
```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start==destination)return 0;
        if(start>destination)swap(start,destination);

        int n=distance.size();
        int sum1=0;
        int sum2=0;
        for(int i=0;i<start;++i)
        {
            sum2+=distance[i];
        }
        for(int i=start;i<destination;++i)
        {
            sum1+=distance[i];
        }
        for(int i=destination;i<n;++i) 
        {
            sum2+=distance[i];
        }
        return min(sum1,sum2);
    }
};
```
