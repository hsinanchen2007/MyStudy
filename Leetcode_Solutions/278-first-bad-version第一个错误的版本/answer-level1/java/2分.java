### 解题思路
此处撰写解题思路

### 代码

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version);
可以理解为在一个重复数组中寻找第一个重复数，这个重复数的isBadVersion函数为true
时间复杂度：O(logn)。搜索空间每次减少一半，因此时间复杂度为:O(logn)。
空间复杂度：O(1)。
*/

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if ( n == 0) {
            return -1;
        }
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = (left + right) >>> 1;
            //如果mid处不是一个错误版本，那第一个错误版本一定在后面
            if (!isBadVersion(mid)) {
                //下一个区间是：[mid+1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
} 
```