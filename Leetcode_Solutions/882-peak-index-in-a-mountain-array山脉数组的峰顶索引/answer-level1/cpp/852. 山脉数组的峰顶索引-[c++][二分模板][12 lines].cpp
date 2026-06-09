
这题和 162 没啥区别。

二分法：如果一个数，大于等于它右侧的数，则解可能是这个元素，也可能在这个元素的左侧。

或者反过来理解：如果一个数，小于它左边的元素，则解一定在它的右侧。

```cpp
int peakIndexInMountainArray(vector<int>& A) {
    int lo = 1, hi = A.size() - 2; 
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (A[mid] >= A[mid+1]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
```
