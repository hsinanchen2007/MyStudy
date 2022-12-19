1. 用split()函数去掉字符串两端的空格
2. 判断是否只有一个单词，即字符串中有没有空格，如果只有一个单词，直接返回字符串长度
3. 有空格，用rpartition()，该函数从右往左用指定的分隔符将字符串分为三部分，最后一个单词在列表中的位置为[2]
```
代码块
```
a = s.strip()
        if " " in a:
            b = list(a.rpartition(' '))
            return(len(b[2]))
        else:
            return(len(a))
        