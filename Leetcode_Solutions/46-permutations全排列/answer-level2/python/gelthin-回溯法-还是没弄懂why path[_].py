### 解题思路
回溯法首题，参见题解 [从全排列问题开始理解“回溯搜索”算法（深度优先遍历 + 状态重置 + 剪枝）](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/) 
liweiwei 又提到了需要动笔画图来进行结题。


这里  
a = []
b= [1,2,3]

a.append(b)  和 a.append(b[:]) 是不一样的。
后者 b[:] 是一个语法糖，相当于 b.copy(),见 [gelthin-tmp +[1] 和 tmp[:] 生成了一个新的对象](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/gelthin-tmp-1-he-tmp-sheng-cheng-liao-yi-ge-xin-de/)

tmp = b[:] ( or  tmp = b.copy())
a.append(tmp)



生成了一个副本，接下来 b 的改变不会影响到 a 的值。

python 入门书上提到了 视图 和 副本 的区别。

需要与另一个写法辨析：[gelthin-解释为何要用 nums1[:]](https://leetcode-cn.com/problems/merge-sorted-array/solution/gelthin-gui-bing-pai-xu-by-gelthin/)

b[:] = a 这个是逐个元素copy


### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(path, nums, used, res, n):
            if len(path) == n:
                res.append(path[:]) # why path[:] 相当于 path.copy() ?
            else:
                for i in range(n):
                    if used[i] == 0:
                        used[i] = 1
                        path.append(nums[i])
                        dfs(path, nums, used, res, n)
                        path.pop()
                        used[i] = 0
        n = len(nums)
        if n==0:
            return [[]]
        else:
            res = []
            path = []
            used = [0]*n
            dfs(path, nums, used, res, n)
        return res
        


```