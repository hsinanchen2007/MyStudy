最基本的二分法
```
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned low=1;
        unsigned high=n;
        if(isBadVersion(low))return low;
        while(low<high)
        {
            unsigned mid=(low+high)>>1;
            if(isBadVersion(mid))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
```
