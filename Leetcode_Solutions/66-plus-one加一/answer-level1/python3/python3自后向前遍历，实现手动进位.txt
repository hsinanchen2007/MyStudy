### 解题思路
思路挺简单，就是自后向前遍历。
若数值为9，则进位，进入下次循环；
否则，直接跳出循环即可。
最后加了个判断条件，是为了处理当遇到[9,9]等特殊情况时，需要在数组最前面再插入一个[1]元素。

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        length=len(digits)
        for i in range(length-1,-1,-1):
            if digits[i]==9:
                digits[i]=0
            else:
                digits[i]=digits[i]+1
                break
        if i==0 and digits[i]==0:
            digits.insert(0,1)
        return digits
```