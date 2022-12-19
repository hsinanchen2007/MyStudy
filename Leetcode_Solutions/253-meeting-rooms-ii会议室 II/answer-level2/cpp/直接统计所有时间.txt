### 解题思路

全部一起排序统计

### 代码

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inter) {
         vector<pair<int,int> > vp(inter.size()*2);
        int ind=0;
        for(auto &i:inter){
            vp[ind++]={i[0],true};
            vp[ind++]={i[1],false};
        }
        sort(vp.begin(),vp.end());
        int ret=0,mm=0;
        for(auto &i:vp){
            if(i.second)mm++;
            else{
                if(mm>ret)ret=mm;
                mm--;
            }
        }
        return ret;
                
    }
};
```