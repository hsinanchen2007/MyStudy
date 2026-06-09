### 解题思路
利用哈希表建立匹配，字符为键 键为序号 参考密码学的简单加密方法。
代码优化算法，利用位运算：异或
首先拿到秘钥，遍历字符，并取字符的编码与其运算，解码就需要拿秘钥再次遍历运算

### 代码

```python3
import random
class Codec:
    def __init__(self):
        self.hash ={}
        #全是值 键位索引 0-self.count
        key_set = ("1","2","3","4","5","6","7","8","9","0",'z','x','c','v','b','n','m',
        'a','s','d','f','g','h','j','k','l','q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M','-','.','/','?',':','#','%','$','&','@','%','=','+',"'",';','(',")",'*')
        self.count = len(key_set)
        #生成键值密码对
        for i in range(1,len(key_set)+1):
            #元素为键 索引为值
            self.hash[key_set[i-1]] = i-1
        #生成随机钥匙数
        # self.key = random.randint(1,self.count)
        self.key = 12

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        #page23
        _str_list = longUrl.split('/',3)
        _str = _str_list[-1]
        ord_list = []
        #得到字符串 把字符串转成序列
        for item in _str:
           ord_list.append(self.hash[item]+self.key)
        res = ''
        #序列数
        for _item in ord_list:
            if _item > self.count:
                _item = _item % self.count
                for k,v in self.hash.items():
                    if v == _item:
                        res += k
                        break
            else:
                for k,v in self.hash.items():
                    if v == _item:
                        res += k
                        break
        return _str_list[0]+"/"+_str_list[1]+"/"+_str_list[2]+"/"+res
    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        _str_list = shortUrl.split('/', 3)
        _str = _str_list[-1]
        ord_list = []
        # 得到字符串 把字符串转成序列
        for item in _str:
            ord_list.append(self.hash[item] - self.key)
        res = ''
        # 序列数
        for _item in ord_list:
            if _item >= 0:
                for k,v in self.hash.items():
                    if v == _item:
                        res += k
                        break
            else:
                for k,v in self.hash.items():
                    if v == self.count + _item:
                        res += k
                        break
        return _str_list[0] + "/" + _str_list[1] + "/" + _str_list[2] + "/" + res

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
```