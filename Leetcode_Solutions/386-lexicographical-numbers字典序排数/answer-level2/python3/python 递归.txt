### 解题思路
递归就解决了，依次以1开头的，2开头的等等，递归结束条件是数字大于n。
外面循环是【1，9】不能以零开头，如果以零开头，递归可能会超时，会出现0，00，000，0000这种无限循环下去的情况
### 代码

```python3
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans=[]
        def helper(pre):
            if pre>n:
                return
            ans.append(pre)
            for i in range(10):
                helper(pre*10+i)
        for i in range(1,10):
            helper(i)
        return ans
```