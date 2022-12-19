1.在字符串使用find函数来找到t中是否包含s的每一个字符，特别快。
2.s中的下一个字符的索引要比上一个字符更大
3.每次对t的遍历是基于上一次索引index+1
```
        index = -1
        for ch in s:
            index2 = t[index+1:].find(ch) + index + 1
            if index2 > index:
                index = index2
            else:
                return False
        return True
```

