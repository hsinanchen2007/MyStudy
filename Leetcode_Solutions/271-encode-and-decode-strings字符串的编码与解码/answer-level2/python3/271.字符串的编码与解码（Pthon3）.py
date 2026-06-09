#### 思路
思路就是将字符串数组格式化`['chen','du','xiu'] -> '4,chen,2,du,3,xiu'`，数字是每个字符串的长度~注释里尽量解释了~你细品
#### 代码
```
class Codec:
    def encode(self, strs: [str]) -> str:
        """Encodes a list of strings to a single string.
        """
        # ['chen','du','xiu'] -> '4,chen,2,du,3,xiu'
        self.encode_res = ''# 加入数组长度
        for i in strs:
            self.encode_res += str(len(i)) + ',' # 加入字符串i的长度
            self.encode_res += i + ',' # 加入字符串i
        return self.encode_res[:-1] # 去掉最后一个逗号

    def decode(self, s: str) -> [str]:
        """Decodes a single string to a list of strings.
        """
        # '4,chen,2,du,3,xiu' -> ['chen','du','xiu']
        self.decode_res = []
        i = 0
        while i < len(s):
            len_word = ''
            # '4 , chen , 2 , du , 3 , xiu'
            #  ^          ^        ^
            # len_word记录单词长度
            while s[i] != ',':
                len_word += s[i]
                i += 1
            # '4 , chen , 2 , du , 3 , xiu'
            #      ^    ^   
            #    start end
            start = i + 1
            end = start + int(len_word)
            self.decode_res.append(s[start:end]) # 将单词添加到结果
            i = end + 1
        return self.decode_res
```
