### 解题思路
直接二分

### 代码

```java []
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        long start = 1L;
        long end = (long)n;

        while(start<end){
            long mid = start + ((end-start)>>1);
            if(isBadVersion((int)mid))
                end = mid;
            else
                start = mid+1;
        }
        return (int)end;
    }
}
```
```python []
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 使用二分法定位错误版本
        start, end, mid = 1, n, -1
        while start<end:
            mid = start + ((end-start)>>1)
            print(start, ' ', mid, ' ', end)
            if isBadVersion(mid) is True:
                end = mid
            else:
                start = mid+1

        return start        

```
```c++ []
typedef long long LL;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        LL start = 1, end = (LL)n+1;
        while(start < end){
            LL mid = start + ((end-start)>>1);
            if(isBadVersion(mid))
                end = mid;
            else
                start = mid+1;
        }
        return (int)end;
    }
};
```