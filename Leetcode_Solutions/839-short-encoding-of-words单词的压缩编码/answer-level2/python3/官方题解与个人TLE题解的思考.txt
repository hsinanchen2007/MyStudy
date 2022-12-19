# 解题思路

其实这个中等难度的题的思路很简单——用最短的`encoding string`表达所有`words`

可以转化为，只要较短的`word`是较长的`word`的尾子串（末尾的子字符串）就不需要将这个较短的word加入到`encoding`的`string`里。

我的思路是没有问题的，就是幻想使用`sorted`对`word`的`length`进行排序后可以提高速度。但可能`sort`本身以及`filter`函数的判断消耗了较多时间。

## 代码

官方题解｜我的题解

```python3 []
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = set(words)
        for word in words:
            for k in range(1, len(word)):
                good.discard(word[k:])

        return sum(len(word) + 1 for word in good)
```

```python3 []
class Solution:
    def minimumLengthEncoding(self, words: list) -> int:
        s_words = sorted(words, key=lambda x:len(x), reverse=True)
        processed = set()
        res = 0
        for i in range(len(s_words)):
            long = s_words[i]
            if long not in processed:
                processed.add(long)
                res += 1+len(long)

                for short in filter(lambda x:len(x)<len(long) and x not in processed, s_words):
                    if short == long[-len(short):]:
                        processed.add(short)
        return res
```

## 知识点

`python3`中`remove(elem)`与`discard(elem)`的区别:

```python3
remove(elem)¶
    # Remove element elem from the set. Raises KeyError if elem is not contained in the set.

discard(elem)
    # Remove element elem from the set if it is present.
```

