### 解题思路


### 代码

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int size = A.size();
        int left = 0, right = size-1, mid = (left+right)/2;
        while(left < right && mid>0 && mid<size-1){
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){
                return mid;
            }else if(A[mid] < A[mid+1]){
                left = mid + 1;
            }else if(A[mid] < A[mid-1]){
                right = mid - 1;
            }
            mid = (left+right)/2;
        }
        return mid;
    }
};
```