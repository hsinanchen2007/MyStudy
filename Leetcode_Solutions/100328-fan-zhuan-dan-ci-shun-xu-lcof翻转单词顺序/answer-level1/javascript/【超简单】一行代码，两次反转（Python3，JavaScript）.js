

## 思路

以"  hello world!  "为例：

- 数据清理， 即将左右空格去掉， 变为"hello world!"
- 按空格拆分单词，变为"  ["hello", "world!"]
- 每个单词都执行一次反转，变为 [olleh", "!dlrow"]
- 将单词用空格拼接起来再执行一次反转，变为 "world! hello"



我们发现其实不需要两次反转，一次就够了，还是以"  hello world!  "为例：

- 数据清理， 即将左右空格去掉， 变为"hello world!"
- 按空格拆分单词，变为"  ["hello", "world!"]
- 单词列表执行一次反转，变为 [world!", "hello"]

> 单词列表执行一次反转，实际上最好的方式是执行交换，即第一项和最后一项交换，第二项和倒数第二项交换等等，但是由于Python和Java等语言String是不可变的，因此我们至少需要N的空间，这种优化对于复杂度没有什么意义，不过感兴趣的同学可以试试。


```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(list(filter(lambda a: a.strip(), s.strip().split(" ")))[::-1])

```

或者更短：

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.strip().split()[::-1])

```


JavaScript:

```js
var reverseWords = function(s) {
  return s
    .split(" ")
    .filter(Boolean)
    .map(str => String.prototype.trim.call(str))
    .reverse()
    .join(" ");
};
```



**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)




