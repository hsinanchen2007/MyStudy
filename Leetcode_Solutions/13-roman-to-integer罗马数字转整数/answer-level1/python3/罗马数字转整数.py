### 解题思路
1.将罗马数字和对应的整数存到一个字典中
2.将字符串转换成列表
3.查看列表中是否存在6种特殊情况，存在的换进行合并处理
4.读取新的列表并将对应的数字相加

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        a = {'I':1,'V':5,'X':10,'L':50,"C":100,"D":500,"M":1000,"IV":4,"IX":9,"XL":40,"XC":90,"CD":400,"CM":900}
        temp = list(s)
        result = 0
        for i in range(len(temp)):
            if len(temp)>1 and i+1 <= (len(temp)-1) and a[temp[i]]<a[temp[i+1]]:
                temp[i] = temp[i]+temp[i+1]
                del temp[i+1]
        for j in temp:
            result += a[j]
        return result
```