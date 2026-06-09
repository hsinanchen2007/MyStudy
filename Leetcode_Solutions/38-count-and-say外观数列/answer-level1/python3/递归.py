### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        ## 递归解法
        if n <= 1:
            return '1'
        list1 = self.countAndSay(n-1)

        count = 1
        list2 = ''
        for i in range(len(list1)):
            if i == 0:
                count = 1
            elif list1[i-1] == list1[i]:
                count += 1
            elif list1[i-1] != list1[i]:
                list2 += str(count) + list1[i - 1]
                count = 1
            if i == len(list1) - 1:
                list2 += str(count) + list1[i]
        return list2
            
```