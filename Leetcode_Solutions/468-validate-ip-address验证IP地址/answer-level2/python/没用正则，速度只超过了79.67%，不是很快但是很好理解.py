### 解题思路
1、将IP按照IPv4得规则拆分为数组
2、判断长度是否符合IPv4长度
    2.1 判断拆分后数组中得每一个地址长度是否为0
    2.2 判断拆分后数组中得每一个是否以 '-' 开头（过滤负数）
    2.3 判断拆分后数组中得每一个地址长度是否大于1且以'0'开头
    2.4 判断拆分后数组中得每一个地址判断是否由数字组成
    2.5 判断拆分后数组中得每一个地址转为数字并判断是否大于255
3、将IP按照IPv6得规则拆分为数组
4、判断长度是否符合IPv6长度
    4.1 判断拆分后数组中得每一个地址长度是否大于0或者大于4
    4.2 判断拆分后数组中得每一个地址是否是16进制得数值
5、根据判断结果返回

### 代码

```python3
class Solution:
    def validIPAddress(self, IP: str) -> str:
        
        def isHex(string):
            for idx, char in enumerate(string):
                if char >= '0' and char <= '9':
                    continue
                if char >= 'a' and char <= 'f':
                    continue
                if char >= 'A' and char <= 'F':
                    continue

                return False

            return True
        
        li = IP.split('.')
        isIP = False

        if len(li) == 4:
            for idx, string in enumerate(li):
                if len(string) == 0:
                    isIP = False
                    break
                if string.startswith('-'):
                    isIP = False
                    break
                if len(string) > 1 and string.startswith('0'):
                    isIP = False
                    break 
                # 判断是否由数字组成
                if string.isdigit() == False:
                    isIP = False
                    break 
                if int(string) > 255:
                    isIP = False
                    break 
                isIP = True

        if isIP == True:
            return "IPv4"
        
        li = IP.split(':')
        if len(li) == 8:
            for idx, string in enumerate(li):
                if len(string) == 0 or len(string) > 4:
                    isIP = False
                    break
                # 判断字符串是否是十六进制
                if isHex(string) == False:
                    isIP = False
                    break
                isIP = True
        
        if isIP == True:
            return "IPv6"
        
        return "Neither"
    
        


```