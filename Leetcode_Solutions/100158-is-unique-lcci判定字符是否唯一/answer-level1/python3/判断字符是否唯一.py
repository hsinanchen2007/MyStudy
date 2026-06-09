### 解题思路
1.将列表换为元组，删除重复的元素，再与原列表长度进行比较(答案)（不符要求）
2.暴力解法，一个一个循环对比
3.利用size为26的bool数组进行迭代比较，若已为1，则有重复
4.利用位运算进行比较，若位已为1，则有重复

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        if len(astr) == len(set(astr)):
            return True
        else:
            return False
```