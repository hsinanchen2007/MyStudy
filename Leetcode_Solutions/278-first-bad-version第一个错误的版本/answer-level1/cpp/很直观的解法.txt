### 解题思路
此处撰写解题思路

### 代码

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long long firstBadVersion(int n) {
    long long low=1,high=n;
    while (low<high) {
        long long mid=(low+high)/2;
        if (isBadVersion(mid)) {
            high=mid-1;
        }
        if (!isBadVersion(mid)) {
            low=mid+1;
        }
        if (isBadVersion(mid)==true&&isBadVersion(mid-1)==false) {
            return mid;
        }
        if (isBadVersion(mid)==false&&isBadVersion(mid+1)==true) {
            return mid+1;
        }
    }
    return low;
}
};
```