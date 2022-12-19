![image.png](https://pic.leetcode-cn.com/7e1b2e3739b873a12f0b530941c6c261de2bd0754a00ac7428a8e751d0fae53c-image.png)

双向列表，简单易懂
```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        temp=collections.deque()
        for num in nums:
            if num%2==0:
                temp.append(num)
            else:
                temp.appendleft(num)
        return list(temp)
```
