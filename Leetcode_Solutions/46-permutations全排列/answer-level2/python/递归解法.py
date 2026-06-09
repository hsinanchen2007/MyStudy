![image.png](https://pic.leetcode-cn.com/0eaa95667d10ae8f20abe93900d2a1be8f938fac15aebef0cdec7da5a6d11d7a-image.png)

递归解法，不断判断去除当前元素的sublist的所有排列组合，再加上当前元素，就是全部解


```python []
def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 1: return [nums]
        ans = []
        for i in range(len(nums)):
            b = nums.copy()
            b.remove(nums[i])
            re = self.permute(b)
            for v in re:
                v.insert(0, nums[i])
                ans.append(v)
        return ans
```


