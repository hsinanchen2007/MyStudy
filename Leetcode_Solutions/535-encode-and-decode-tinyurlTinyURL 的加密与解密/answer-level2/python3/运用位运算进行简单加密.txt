### 解题思路
异或运算的性质：任意数与其本身异或等于0 0与任意数异或等于其本身 满足交换律 应用：拿到秘钥与其第一运算，再一次运算就还回来了，就像灰太狼又回来了！！！！

### 代码

```python3
import random
class Codec:
    def __init__(self):
        self.key =random.randint(1,100)
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        #page23
        _str_list = longUrl.split('/',3)
        _str = _str_list[-1]
        ord_list = []
        #得到字符串 把字符串转成序列
        for item in _str:
           ord_list.append(ord(item)^self.key)
        res = ''
        for _item in ord_list:
            res += chr(_item)
        return _str_list[0]+"/"+_str_list[1]+"/"+_str_list[2]+"/"+res
    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        _str_list = shortUrl.split('/', 3)
        _str = _str_list[-1]
        ord_list = []
        for item in _str:
            ord_list.append(ord(item) ^ self.key)
        res = ''
        for _item in ord_list:
            res += chr(_item)
        return _str_list[0] + "/" + _str_list[1] + "/" + _str_list[2] + "/" + res

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
```