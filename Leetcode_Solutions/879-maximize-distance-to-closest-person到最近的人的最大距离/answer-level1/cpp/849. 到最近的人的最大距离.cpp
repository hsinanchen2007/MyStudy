## 分别计算出前面、中间和后面的空位数
**条件 “seats 中至少有一个 0，且至少有一个 1” 很重要**
```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size(), front0=0, back0=0, max_cnt=0, i=0;
        for(; seats[i]==0; i++) front0++;
        int cnt=0;
        for(; i<len; i++){
            if(seats[i]==0) cnt++;
            else{
                max_cnt = max(max_cnt, cnt);
                cnt=0;
            }
        }
        max_cnt = (max_cnt+1)/2;
        for(i=len-1; seats[i]==0; i--) back0++;
        return max(max(front0, back0), max_cnt);
    }
};
```