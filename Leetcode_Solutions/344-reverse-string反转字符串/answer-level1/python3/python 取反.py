### 解题思路
思路其实很简单，range设为一半，不断交换即可，python本身就可以直接负数取倒数，0对应-1，1对应-2，0和-1有啥关系？**0取反就是-1**，同理，1取反就是-2。

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)//2):
            s[i], s[~i] = s[~i], s[i]

```