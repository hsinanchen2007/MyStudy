**思路**
由于版本列表错误的版本都是在右侧。$isBadVersion$的结果如$[false, false,...,true, true,..., true]$。因此这里可以使用二分找到第一个$true$。当$isBadVersion(mid)$ 为$true$的时候，我们判断如果$mid$是第一个版本，或者$mid-1$不是错误的版本，那我们就能断定$mid$就是第一个错误的版本。否则，说明第一个版本在左侧，更新$high = mid - 1$。如果$isBadVersion(mid)$ 为$false$的时候，说明第一个错误在右侧, 更新$low = mid + 1$. 具体代码如下：
```java
 public class Solution extends VersionControl {
        public int firstBadVersion(int n) {
            int low = 1;
            int high = n;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                if (isBadVersion(mid)) {
                    if (mid == 0 || !isBadVersion(mid - 1)) {
                        return mid;
                    }
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return -1;
        }
    }
```

**复杂度**
时间复杂度：$O(logn)$
空间复杂度：$O(1)$