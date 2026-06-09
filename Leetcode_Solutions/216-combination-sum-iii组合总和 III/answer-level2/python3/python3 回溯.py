### 解题思路
此处撰写解题思路
典型的回溯模板，索引去除选过的数字，限制了1-9，所以一开始初始可以选择的数字就是1-9，也就是下面的a
还是很简单的一道题目

### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        a = list(range(1,10))
        ans = []
        def helper(a,n,k,res):
            if n==0 and k==0:
                ans.append(res[:])
            if n<0 or k<0:
                return 
            for i in range(len(a)):
                helper(a[i+1:],n-a[i],k-1,res+[a[i]])
        
        helper(a,n,k,[])
        return ans

```