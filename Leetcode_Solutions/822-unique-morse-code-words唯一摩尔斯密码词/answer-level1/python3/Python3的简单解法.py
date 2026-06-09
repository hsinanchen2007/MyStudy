### 思路
思路比较直接，将`words`中每个单词的每个字符转换成摩斯码，返回不同“摩斯单词”的个数。
Python提供的内置函数有`map(fun,iter)`，我们可以有更好的选择：`str.maketrans()`和`str.translate()`，前者创建翻译表、后者翻译字符串。
1. `maketrans(x, y=None, z=None, /)`: Return a translation table usable for `str.translate()`.
    1. If there is only one argument, it must be a dictionary mapping Unicode ordinals (integers) or characters to Unicode ordinals, strings or None. Character keys will be then converted to ordinals.
    2. If there are two arguments, they must be strings of equal length, and in the resulting dictionary, each character in `x` will be mapped to the character at the same position in `y`. 
    3. If there is a third argument, it must be a string, whose characters will be mapped to None in the result.

2. `str.translate(table, /)`: Replace each character in the string using the given translation table.
    1. `table`: Translation table, which must be a mapping of Unicode ordinals to Unicode ordinals, strings, or None.
    2. The table must implement lookup/indexing via __getitem__, for instance a dictionary or list.  If this operation raises LookupError, the character is left untouched.  Characters mapped to None are deleted.

`maketrans()`实际上也是创建了一个字典，只不过其键为ASCII码。

### 代码

```python3
def uniqueMorseRepresentations(words):
    code={'a':".-",'b':"-...",'c':"-.-.",'d':"-..",'e':".",'f':"..-.",'g':"--.",'h':"....",'i':"..",'j':".---",'k':"-.-",'l':".-..",'m':"--",'n':"-.",'o':"---",'p':".--.",'q':"--.-",'r':".-.",'s':"...",'t':"-",'u':"..-",'v':"...-",'w':".--",'x':"-..-",'y':"-.--",'z':"--.."}
    result=[i.translate(str.maketrans(code)) for i in words]
    return len(set(result))
```
也可以用集合生成式：
```python3
def uMR(words):
    code={···}
    return len({i.translate(str.maketrans(code)) for i in words})
```

### 结果
看了一些评论是将每个单词的字母逐一映射，然后拼接，有些繁琐，使用内置的`translate()`方法会相对简洁一些。但是运行效率...如图...
![QQ浏览器截图20200212205116.png](https://pic.leetcode-cn.com/2f9fbe7141a1eaa263332c7bfd42ffc5262b91aed861934645d1496bc676a573-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200212205116.png)
