```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int res=0,sum=0;
        if(start>destination) {   //如果目的地在出发的前面，换一下
            int temp=start;
            start=destination;
            destination=temp;
        }
        for(int i=start;i<destination;i++){  //计算顺时针的距离
            res+=distance[i];
        }
        for(int i=0;i<distance.size();i++){  //计算总的路程距离
            sum+=distance[i];
        }
        return (sum-res)>res?res:(sum-res);
    }
};
```
