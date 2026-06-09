# 内置函数
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]  # 取第三项到最后一项（二进制前两位为0b）
```
# 非内置函数
```
# 二进制相加：满二进一
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        r, p = '', 0
        d = len(b) - len(a)
        # 高位不齐补0：a = '0101' b = '1101'
        a = '0' * d + a
        b = '0' * -d + b
        for i, j in zip(a[::-1], b[::-1]):  # 逆向打包为元组(i,j=id,name)
            s = int(i) + int(j) + p
            r = str(s % 2) + r  # 求余;逆向相加 != (r += str(s % 2))
            p = s // 2  # 取整
        return '1' + r if p else r  
        # p(true),return '1' + r; p(fasle),return r
```
![微信图片_20200410111006.jpg](https://pic.leetcode-cn.com/0e6a1fc3372338a81d13b530e49fe89396d2d570e10e9c14425604455baf0822-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200410111006.jpg)
作者：QQqun902025048
链接：https://leetcode-cn.com/problems/add-binary/solution/python-1xing-nei-zhi-han-shu-fei-nei-zhi-jie-fa-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。