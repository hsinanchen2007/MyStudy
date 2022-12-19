看到直接 `return url` 的提交记录我也是醉了，又一个面向测试编程。。。
参考官方题解第5种，将请求次数作为 `key`，使用随机数将 `key` 编码为 6 位短链字符串，更加安全。

废话不多说，直接上代码：
```
import random


class Codec:
    # URL简化类，将一个长url转化为 一个6位字母数字结尾的短url
    _chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    _map = {}
    _key = ''.join(random.sample(_chars, 6))

    def encode(self, longUrl):
        """
        将 一个长 URL 编码为 一个短 URL.

        方法：将请求次数作为key，先将 次数 转化为一个 6位字符串，容器数据类型为 dict
        然后将该字符串作为 key 进行加密，值为对应的 longUrl

        转化算法：使用长度为 62 位的由大小写字母和数字构成的集合作为 62 进制位表
        6位长度字符可表示的 url 数量为 62**6 = 586亿多，不够用的话可以再增加位数

        优化：使用 random 模块 随机从 62 位字符串中选取 6 个作为 shortURL
        这样一来，根据 shortUrl 来预测请求次数几乎是不可能的，数据更加安全。
        """
        while self._map.get(self._key):
            self._key = ''.join(random.sample(self._chars, 6))

        self._map[self._key] = longUrl
        return 'http://tinyurl.com/' + self._key

    def decode(self, shortUrl):
        """
        将 一个短 URL 解码为 一个长 URL，直接根据后 6 位从字典取值即可。

        只截取后6位部分：19=len("http://tinyurl.com/")
        """
        return self._map[shortUrl[19:]]
```
