### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def toHex(self, num: int) -> str:
        dict1={0:"0",1:"1",2:"2",3:"3",4:"4",5:"5",6:"6",7:"7",8:"8",9:"9",10:"a",11:"b",12:"c",13:"d",14:"e",15:"f"}
        res=""
        num &= 0xFFFFFFFF
        while(num):
            cur=num%16
            res=dict1[cur]+res
            num=num//16
        if res=="":
            res="0"
        return res
```