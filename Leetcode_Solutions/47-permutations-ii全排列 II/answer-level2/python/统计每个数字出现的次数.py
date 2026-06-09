### 解题思路

cnts 是每个数字出现的次数
每次使用一个数字都尝试使用 1 个、2 个 ... 到用完这个数字。除此之外，不允许有两次连续选择相同数字

### 代码

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        import collections
        n = len(nums)
        cnts = collections.Counter(nums)
        nums = list(cnts.keys())
        l = [0] * n
        ans = []
        def dfs(i):
            if i == n:
                ans.append(l[::])
                return
            for num in nums:
                if i > 0 and l[i-1] == num: continue
                oc = cnts[num]
                if oc > 0:
                    j = 0
                    while cnts[num] > 0:
                        cnts[num] -= 1
                        l[i + j] = num
                        dfs(i+j+1)
                        j += 1
                    cnts[num] = oc
        dfs(0)
        return ans
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)