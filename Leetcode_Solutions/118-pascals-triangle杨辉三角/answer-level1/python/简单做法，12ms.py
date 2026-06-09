### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        return_list = list()
        for i in range(numRows):
            # 判断现在处于第几行
            item_list = []
            for j in range(i+1):
                if j == 0:
                    item_list.append(1)
                    continue
                try:
                    item_list.append(return_list[i-1][j-1] + return_list[i-1][j])
                except IndexError:
                    item_list.append(1)
            return_list.append(item_list)
        return return_list
```