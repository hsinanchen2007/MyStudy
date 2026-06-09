### 解题思路
双指针，一个从小往大，一个从大往小
len()：输出元素个数
return()：输出结果并终止

### 代码

```python
class Solution(object):
    def twoSum(self, numbers, target):
        n = len(numbers)
        i = 0
        j = n -1 
        while (i<j):
            if numbers[i] + numbers[j] == target:
                return(i+1,j+1)
            elif numbers[i] + numbers[j] > target:
                j -= 1
            else:
                i += 1
```