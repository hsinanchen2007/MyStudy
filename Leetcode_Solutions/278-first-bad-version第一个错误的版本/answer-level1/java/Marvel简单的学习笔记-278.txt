### 解题思路
典型的二分题，不过要注意溢出的问题。
while(lo<hi)
满足条件时，hi=mid;
不满足条件时，lo=mid+1;
lo==hi时，lo即答案。
属于求解第一个满足条件的数的问题。
时间复杂度：O(logn)。二分查找属于对数级别的算法。
空间复杂度：O(1)。

### 代码

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lo=1,hi=n;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isBadVersion(mid))   hi=mid;
            else                    lo=mid+1;
        }
        return lo;
    }
}
```