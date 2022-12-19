按照大神说的，不转10进制计算，模拟进位，算法有点傻。。
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = ''.join(reversed(a))
        b = ''.join(reversed(b))
        result = ''
        JinWei = ''
        ZhongZhiWei = min(len(a),len(b))
        for i in range(0, ZhongZhiWei):
            c = a[i] + b[i] + JinWei
            JinWei = str(c.count('1') // 2)
            result += str(c.count('1') % 2)
        result2 = a[ZhongZhiWei:]
        result2 += b[ZhongZhiWei:]
        ZhongZhiWei = 0
        while JinWei == '1':
            c = result2[ZhongZhiWei:ZhongZhiWei+1] + JinWei
            result += str(c.count('1') % 2)
            JinWei = str(c.count('1') // 2)
            ZhongZhiWei += 1
        result += result2[ZhongZhiWei:]
        return ''.join(reversed(result))
            
        
```
