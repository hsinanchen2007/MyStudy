```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int l=0,m=0;
        int n=distance.size();
        if(start<=destination){
            for(int i=start;i<destination;++i)
               l+=distance[i];
            for(int i=destination;i<n;++i)
                m+=distance[i];
            for(int i=0;i<start;++i)
                m+=distance[i];
        }
        else{
            for(int i=start;i>destination;--i)
               l+=distance[i-1];
            for(int i=destination;i>0;--i)
                m+=distance[i-1];
            for(int i=n;i>start;--i)
                m+=distance[i-1];            
        }
        return min(l,m);
    }
};
```
