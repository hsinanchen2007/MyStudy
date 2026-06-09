### 解题思路
二分加移位

### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=0;
        int hi=n;
        int mi=lo+((hi-lo)>>1);
        while(lo<hi){
            if(isBadVersion(mi)){
                hi=mi;
                mi=lo+((hi-lo)>>1);
            }
            else{
                lo=mi+1;
                mi=lo+((hi-lo)>>1);
            }
        }
        return lo;
    }
};
```