**利用Python自带的数据类型转换，两行代码解题：**

```python
def addBinary(self, a, b):
        s = int(a,2) + int(b,2)
        return(bin(s)[2:])
```
结果可击败90%+的提交者
![QQ截图20190908211222.png](https://pic.leetcode-cn.com/c4a6089c2fb643b22bc8cf1c9fa922524e4bf1b8fc31e99f6d345f4449f77213-QQ%E6%88%AA%E5%9B%BE20190908211222.png)
