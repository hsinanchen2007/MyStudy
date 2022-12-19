### 解题思路
比较哈希集合前后的长度
![image.png](https://pic.leetcode-cn.com/86eadf9b258019e6c3c27a3adf5f120028bd06e3ab532d3035104084ac37ba47-image.png)

### 代码

```python
class Solution(object):
    def containsDuplicate(self, nums):
        return len(nums)>len(set(nums))
```