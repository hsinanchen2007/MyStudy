### 思路
* 先找到max_left 和 min_right，确定一个合理的区间。再在这个区间里找target
* 找到边界值后，二分就非常可靠了
### 代码

``` python
class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        left =0;
        #取多少都可以，自己随意
        right = target if target!=0 else abs(target)
        while reader.get(right)!=2147483647 and reader.get(right)<target:
            if reader.get(left)<target :
                break
            left = right
            right= 2*right
        right = max(right,19999)
        while left <right:
            mid=(left+right)>>1
            if reader.get(mid)<target:
                left=mid+1
            else:
                right=mid
        return left if reader.get(left)==target else -1

```