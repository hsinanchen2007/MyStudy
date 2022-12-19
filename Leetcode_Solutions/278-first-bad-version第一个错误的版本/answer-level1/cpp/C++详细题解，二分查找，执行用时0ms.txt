### 思路
这里要查找的是第一个错误版本，因此我们在查找到错误版本时，还需要判断该版本的前一个版本是不是正确版本。
```cpp
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        if(isBadVersion(1))  return 1;
        while(left < right){
        // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if(!isBadVersion(mid - 1) && isBadVersion(mid)) return mid;
            else if(!isBadVersion(mid)) left = mid + 1;
            else    right = mid;
        }
        // Post-processing:
        // End Condition: left == right
        if(isBadVersion(left) && !isBadVersion(left - 1)) return left;
        return -1;
    }
};
```
