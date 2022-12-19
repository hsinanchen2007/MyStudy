### 解题思路
先排除六种特殊情况，再转化为数字，最后求和即可

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        list1 = ['IV','IX','XL','XC','CD','CM']
        list2 = [4,9,40,90,400,900]
        tmp = []
        for i,value in enumerate(list1):
            if value in s:
                s = s.replace(value,'')
                tmp.append(list2[i])
        list3 = ['I','V','X','L','C','D','M']
        list4 = [1,5,10,50,100,500,1000]
        for value in s:
            index = list3.index(value)
            tmp.append(list4[index])
        return sum(tmp)

            
```