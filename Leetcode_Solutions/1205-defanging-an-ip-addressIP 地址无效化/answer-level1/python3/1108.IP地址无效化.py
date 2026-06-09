第一种方法：使用replace
注意：replace进行替换不改变源字符串
```python []
class solution:
    def IPaddr(self,address):
        return address.replace(".","[.]")
```
第二种：采用list的替换方式,运行效率更高
```python []
class solution:
    def IPaddr(self,address):
        address = list(address)
        address = ['[.]' if i=='.' else i for i in address]
        "".join(address)
        return address
```
