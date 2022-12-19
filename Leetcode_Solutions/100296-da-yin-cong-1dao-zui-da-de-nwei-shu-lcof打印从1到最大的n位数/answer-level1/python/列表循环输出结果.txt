### 解题思路
最大值为10的n次方减去1.然后循环输出结果

### 代码

```python3
class Solution:
    def printNumbers(self, n: int):
        max =10**n-1
        list1 =[]
        for i in range(1,max+1):
            list1.append(i)
        return list1
```