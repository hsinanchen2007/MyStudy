### 1.python切片
- 下面是python`list`的时间复杂度,可以看到我们得到一个切片的时间复杂度为`O(k)`
- 所以此方法的时间复杂度为`O(n)`
![image.png](https://pic.leetcode-cn.com/7d397b4d37e0320c93e2e467b2c947196a1c91d0785ee2853c8d758e08eb9b1d-image.png)
![image.png](https://pic.leetcode-cn.com/7a5d2a3ac08159343770cc4be78b874540c4b5c0dbd7781057a6d2f05d4e402e-image.png)

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        if n > len(s) or not s:
            return ''
        return s[n:] + s[:n]


```
- 上面是使用的`+`将字符串进行相连,但是在python中当数据量很大时`+`的操作是效率很低的
- 我们采用另外一种方式,使用`join`方法实现,在对于大数据时它的效率要高于`+`
- 因为`+`操作是生成一个新的字符串,需要创建额外的内存,当数据量大时会很耗内存的
- `join`对多个字符进行连接时效率高，只会有一次内存的申请。而且如果是对list的字符进行连接的时候，这种方法必须是首选
![image.png](https://pic.leetcode-cn.com/fe15848be522f1c13b6cd0a39449b701d3694475312b62b4b68f82cc37e52667-image.png)
```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        if n > len(s) or not s:
            return ''
        return ''.join([s[n:],s[:n]])


```
### 2.三次旋转法
![image.png](https://pic.leetcode-cn.com/8a5ad8568c6dcbbb1ebf6d927d6ec37e5b7145966c94bb6e9937f9fdec63364d-image.png)
- 其实这个问题是<<翻转单词顺序>>的一个衍生
- 我们来看例子`s = "abcdefg", k = 2`
- 步骤:
1. 先将`s`看成两部分`s[:2]`和`s[2:]`,然后分别翻转这两部分,此时`s`变为`s = "bagfedc"`
2. 再将现在的`s`进行翻转,变成`s = "cdefgab"`,这就是结果喽!

- 时间复杂度为`O(n)`
### 代码
```
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        if n > len(s) or not s:
            return ''
        s = list(s)
        def reverse(start, end):
            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
        length = len(s) - 1
        reverse(0, n-1)
        reverse(n,length)
        reverse(0, length)
        return ''.join(s)
```

