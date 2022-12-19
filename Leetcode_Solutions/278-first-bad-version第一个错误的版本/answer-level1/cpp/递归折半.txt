```
bool isBadVersion(int version);

class Solution {
public:
    int call(int low, int high){
        if(low==high)
            return low;
        else{
            int mid = low + (high - low)/2;  
            if(isBadVersion(mid))
                return call(low,mid);
            else
                return call(mid+1,high);
        }
 
    }
    int firstBadVersion(int n) {
        return call(1,n);
    }
};
```
