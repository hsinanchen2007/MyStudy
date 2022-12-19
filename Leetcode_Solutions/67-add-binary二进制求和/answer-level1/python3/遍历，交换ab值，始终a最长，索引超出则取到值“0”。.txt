### 解题思路
遍历，交换ab值，始终a最长，索引超出则取到值“0”。
模拟手工计算。

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:     
        if len(a)<len(b):a,b=b,a
        point_a=len(a)-1
        point_b=len(b)-1

        result=""
        add="0"
        while point_a!=-2:
            ones=0
            if point_a<0:
                char_a=" "
            else:
                char_a=a[point_a]
            if point_b<0:
                char_b="0"
            else:
                char_b=b[point_b]

            if char_a=="1":ones+=1
            if char_b=="1":ones+=1
            if add=="1":ones+=1
            if ones>=2:
                add="1"
            else:
                add="0"
            result=str(ones%2)+result
            point_a-=1
            point_b-=1
        return result if result[0]=="1" else result[1:]
```