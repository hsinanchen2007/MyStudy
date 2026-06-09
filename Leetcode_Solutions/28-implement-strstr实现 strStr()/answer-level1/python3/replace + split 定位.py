```
 def strStr(self, haystack, needle):
        """
        查找needle  在 haystack  中什么位置

        """
        if len(needle.replace(' ', '')) == 0:
            return 0
        a = haystack.split(needle)[0]
        pos = len(a)
        return pos if a != haystack else -1
```

