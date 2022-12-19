### 解题思路
![image.png](https://pic.leetcode-cn.com/92fcbbaf137e0ef5f3074b8f677ec38f1ea18d35269d63da74c2de19f55ff6ad-image.png)
用生成器遍历并移除所有val然后直接返回nums长度


### 代码

```python3
class Solution:
            
    def removeElement(self, nums: List[int], val: int) -> int:
        def remove_gen(ls, val):
            while True:
                try:
                    ls.remove(val)
                    yield
                except ValueError:
                    return len(ls)
        list(remove_gen(nums, val))
        return len(nums)
    
    

```