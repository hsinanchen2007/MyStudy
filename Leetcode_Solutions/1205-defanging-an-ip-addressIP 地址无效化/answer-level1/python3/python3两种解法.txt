解法一：先将字符串转为列表，遍历该列表替换'.'为'[.]'r，最后将列表转为字符串，用join函数添加进address
        用str()直接转化会出问题


```
class Solution:
    def defangIPaddr(self, address: str) -> str:
        address=list(address)
        for i in range(len(address)):
            if address[i]=='.':
                address[i]='[.]'
        address=''.join(str(i) for i in address)
        return address
```

解法二： 一行python投机取巧
```
class Solution:
    def defangIPaddr(self, address: str) -> str:
        address=address.replace('.','[.]')
             return address
```
