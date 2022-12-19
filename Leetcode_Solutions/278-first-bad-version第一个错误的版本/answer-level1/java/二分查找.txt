此题核心是二分查找。
要注意，返回的是第一个错误版本，而不是找到一个错误版本就返回。
因此最后需要返回是查找的范围的下界。
代码如下：
```
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while (lo <= hi) {
            int mid = lo+(hi-lo)/2;
            if (!isBadVersion(mid)) lo = mid+1;
            else if (isBadVersion(mid)) hi = mid-1;
        }
        return lo;
    }
}
```
