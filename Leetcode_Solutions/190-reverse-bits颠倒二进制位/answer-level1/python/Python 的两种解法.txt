### 解一

Python 一行代码：

1. `n` 转为二进制并去掉前缀 `0b`
2. 左侧填充 0 到 32 位
3. 翻转字符串
4. 转为十进制表示

知识点：

- [Python bin() 函数](https://www.runoob.com/python/python-func-bin.html)
- [Python zfill()方法](https://www.runoob.com/python/att-string-zfill.html)
- [python进制转换（二进制、十进制和十六进制）及注意事项](https://m.pythontab.com/article/86)

```
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return int(bin(n)[2:].zfill(32)[::-1], base=2)
```

### 解二

二进制移位。

取出 n 的最低位，加入结果 res 中。然后 n 右移，res 左移。循环此过程。

```python
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        res = 0
        count = 32
        
        while count:
            res <<= 1
            # 取出 n 的最低位数加到 res 中
            res += n&1
            n >>= 1
            count -= 1
            
        return int(bin(res), 2)
```

----

## 🐱

- 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
- 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
- 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)