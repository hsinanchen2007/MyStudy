```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 0;
        while(A[i]<A[i+1])
            i++;
        return i;
    }
};
```
