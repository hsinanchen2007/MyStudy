### 解题思路
1.列表转字符串
2.字符串转整型
3.整型+1
4.整型转字符串
5.字符串转列表
执行用时 :20 ms, 在所有 Python 提交中击败了77.43%的用户
内存消耗 :11.7 MB, 在所有 Python 提交中击败了77.09%的用户
### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits_str=''
        for i in range(len(digits)):
            digits_str+=str(digits[i])
        digits_num=int(digits_str)+1
        digits_list=list(str(digits_num))
        return digits_list
```