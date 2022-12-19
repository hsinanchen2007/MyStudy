IPv4先用正则匹配出格式，再split一下每一段确保在0-255之间
IPv6直接用正则就好
小技巧：可以先给IP补上"."号或":"号，以方便匹配

```
class Solution:
    def validIPAddress(self, IP: str) -> str:
        if self.isIPv4(IP):
            return "IPv4"
        elif self.isIPv6(IP):
            return "IPv6"
        else:
            return "Neither"
        
        
    def isIPv4(self, IP: str) -> bool:
        import re
        # 格式校验
        IP = IP+"."
        pv4 = re.compile(r"(([1-9]\d{0,2}|[0])\.){4}") # .号要记得转义\
        m = pv4.fullmatch(IP) # 全匹配
        IP = IP[0:-1] # 去掉尾部.号
        if m is None:
            return False
        # 校验大小
        #print(m.group())
        ip_list = list(map(lambda x: int(x), IP.split(".")))
        for part in ip_list:
            if part > 255 or part < 0:
                return False
        return True
        
    def isIPv6(self, IP: str)->bool:
        import re
        IP = IP+":"
        pv6 = re.compile(r"(([\dA-Fa-f]{1,4}):){8}")
        m = pv6.fullmatch(IP)
        IP = IP[0:-1]
        if m is None:
            return False
        return True
                
```

![image.png](https://pic.leetcode-cn.com/20ba4f6e01ab18faa6263a9a2e8c9eb6a4049b2bdcb8ea91a9c08dd26fbe4c9f-image.png)
