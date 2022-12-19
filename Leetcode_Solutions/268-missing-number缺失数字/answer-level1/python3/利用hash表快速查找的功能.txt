![image.png](https://pic.leetcode-cn.com/779e4ff5cc7e8df6c5db480638ff9b49a6e15f5eadfa9edca9c7a6597e67e5eb-image.png)
```
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        hash = {} # 把所有的元素放在hash表里
        for i in range(len(arr)):
            hash[arr[i]] = 0.0
        for i in range(len(arr) + 1): # 从0开始判断元素是否存在
            if i not in hash:
                return i # 不存在直接返回当前元素
```
