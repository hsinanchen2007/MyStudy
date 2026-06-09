```
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        long long mid = low + (high-low) / 2;
        while(low < high)
        {
            if(isBadVersion(mid))
            {
                high = mid;
            }else{
                low = mid + 1;
            }
            mid = low + (high-low) / 2;
        }
        return low;
    }
};
```
