### 解题思路
此处撰写解题思路
1.现将这个列表做成一个整数
2.将这个整数+1实现目标
3.将这个整数的各个个十百千万位置依次放回表格
tip：
需要注意的是列表[9]，计算结果为[1,0],应考虑进位
### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        a=len(digits)
        c=0
        for i in range(a):
            b=digits[i]*10**(a-1-i)
            c=c+b
        c=c+1
        c=str(c)
        d=len(c)
        for i in range(a):
            digits[i]=int(c[i])
        if a==d:
            return digits
        else:
            digits.append(0)   
            return digits 
        
```