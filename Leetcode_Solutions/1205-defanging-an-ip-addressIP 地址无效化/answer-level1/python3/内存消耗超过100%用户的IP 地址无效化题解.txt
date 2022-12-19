```python
class Solution:
    def defangIPaddr(self, address: str) -> str:
        # 将字符串以.为分隔符进行分割.  "1.1.1.1" ===> ['1', '1', '1', '1']
        items = address.split('.')
        # 通过[.]连接符将s列表d里面的每个元素拼接。  ['1', '1', '1', '1'] ===> "1[.]1[.]1[.]1"
        return "[.]".join(items)
```

![image.png](https://pic.leetcode-cn.com/3ea8524deeaa430486866d80024decbd12ebd373aa13ab400ae0706b92fc62e8-image.png)
