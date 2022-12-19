![1586357755(1).jpg](https://pic.leetcode-cn.com/43ed5511d3311aa2e9385f3cdf6634290651cbceb272d8ef3aae137c10845fc5-1586357755\(1\).jpg)

二分查找要注意不要陷入死循环，最后要检查一下是否需要单独检验起始点。
```
class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,mid;
        while(l<r){
            mid=l+(r-l+1)/2;
            if(isBadVersion(mid)) r=mid-1;
            else l=mid;
        }
        if(isBadVersion(l)) return l;
        return l+1;
    }
};
```
