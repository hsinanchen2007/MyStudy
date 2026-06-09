### 解题思路
递归解决：
    首先拿到height列表除去头尾的最大值和头尾的值，即：height[0]、height[-1]、max(height[1:-1])
分类如下：
    一、两头大、中间小（相等也可以）
        这样的情况不需要再递归了，可以直接计算返回
![image.png](https://pic.leetcode-cn.com/3aa3f87e7c9f048c4d789d23ca3f490c931a0d55c75dcb09ec8b4fb496a90820-image.png)

    二、中间比两边都大（相等也可以，但是没必要，直接归入分类一中计算）
        这种情况的返回值等于左右两部分的值相加，没法直接计算（递归调用）
![image.png](https://pic.leetcode-cn.com/0f672afeac27bbfae937e2420a4866e2993dd4b7d0bef1e39aac33decdc2a0e8-image.png)


    三、三个数递增或递减
        这种情况的返回值也等于左右两部分的值相加。由于中间是除了头尾意外的最大值，所以较大的那一边可以直接计算出（和分类一样）；较小的一边不能直接计算，需要递归调用。（由于比较懒，我就直接把分类二和分类三合并了，较大的一边会多调用一次）
![image.png](https://pic.leetcode-cn.com/b2675d3bd58578ba722c45869cf8217817505049a56dc363b4576325ca0f9497-image.png)


复杂度：
    max():O(n)
    index():O(n)
    sum():O(n)
    切片：O(k)
    递归调用次数：最坏是n次(height数组是递增的))



### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <=2:return 0
        maxint = max(height[1:-1])
        i = height[1:-1].index(maxint)+1
        if height[0]>=maxint and height[-1]>=maxint:
            return (len(height)-2)*min(height[0],height[-1])-sum(height[1:-1])        
        else:        
            return self.trap(height[:i+1])+self.trap(height[i:])

        
            
```