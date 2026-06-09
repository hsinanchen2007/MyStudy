
方法一：遍历
```python []
class Solution:
    def defangIPaddr(self, address: str) -> str:
        ans=list()
        for i in list(address):
            if i =='.':
                ans.append('[.]')
            else:ans.append(i)
        return "".join(ans)
```
方法二，用内置方法直接替换
```python []
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".","[.]")
```