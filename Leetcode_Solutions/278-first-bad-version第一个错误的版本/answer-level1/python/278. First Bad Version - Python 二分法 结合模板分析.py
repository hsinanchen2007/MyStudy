#### 思路：
 - 参考了[@liweiwei1419](https://leetcode-cn.com/u/liweiwei1419)分享的[二分法模板](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)：
 - 二分法排除非目标元素的关键（依据）：
   如果中位数是好版本（通过质量检测），则起始坏版本一定在中位数之后；
这个判断比较好理解，同时排除了中位数，契合模板的要求
#### 效率：
> Runtime: 28 ms, faster than 97.93% of Python3 online submissions for First Bad Version.
> Memory Usage: 13.8 MB, less than 6.90% of Python3 online submissions for First Bad Version.
#### 复杂度分析：
 - 时间复杂度：$O(\log n)$
   每搜索一次空间减少一半
 - 空间复杂度：$O(1)$
   创建了两个（常数级）的变量
#### 代码：
```Python
class Solution(object):

    def firstBadVersion(self, n: int) -> int:
        
        # 左右边界的起始值，最小版本为1，最大版本为n
        left, right = 1, n

        while left < right:

            # 根据下面的排除条件，左边界排除了中位数，因此选择左中位数
            mid = (left + right) >> 1

            # 如果中位数是好版本（通过质量检测），则起始坏版本一定在中位数之后
            if not isBadVersion(mid):
                left = mid + 1
            else:
                # 否则，起始坏版本可能是中位数，或者中位数之前
                #（注意这里并不能排除中位数）
                right = mid

        # 返回的结果一定是版本号之一，所以不用做是否版本号的判断
        return left

```
