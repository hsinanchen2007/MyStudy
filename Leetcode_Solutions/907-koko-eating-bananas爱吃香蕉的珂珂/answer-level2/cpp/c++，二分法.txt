### 解题思路
此处撰写解题思路
这个题目主要 是二分法的运用，因为piles.length <= H <= 10^9，所以piles中的最大值为速度，肯定能吃完。
第二，如果顺序查找的话，肯定会超时，所以确定 了最小边界为1，最大边界为max(piles)的时候，那么就可以用一分法查找这个临界点。
### 代码

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int  lo  = 0;
        int  hi = 0;
          for(auto val: piles){
              hi = max(hi,val);
        }
        lo = 1;
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            if(canEatOver(piles, mid) <= H)
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
    int canEatOver(vector<int>& piles,int speed)
    {
        int sum = 0;
        for(auto val: piles) {
           sum += ((val+speed-1)/ speed);
        }
        return sum;
    }
};
```