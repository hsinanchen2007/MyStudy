```
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size()==0) return 0;
        int maxdis = 0;
        int dis = 0;
        int front = 0;
        int end = seats.size()-1;
        if(seats[0]==0){//头部
            for(;front<seats.size();front++){
                if(seats[front]==1) break;
                else dis++;
            }
        }
        maxdis =dis;dis=0;
        if(seats[seats.size()-1]==0){//尾部
            for(end;end>=0;end--){
                if(seats[end]==1) break;
                else dis++;
            }
        }
        maxdis = maxdis>dis?maxdis:dis;
        dis = 0;
        for(front;front<=end;front++){
            if(seats[front]!=1) dis++;
            else{
                dis = (dis+1)/2;//这里容易出错
                maxdis = maxdis>dis?maxdis:dis;
                dis =0;
            }
        }
        return maxdis;
    }
};
```
