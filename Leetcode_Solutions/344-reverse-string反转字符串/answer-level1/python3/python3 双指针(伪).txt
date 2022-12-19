![QzpcVXNlcnNcSkhabWFcQXBwRGF0YVxSb2FtaW5nXERpbmdUYWxrXDYyMDE5ODQ1OF92MlxJbWFnZUZpbGVzXDE1ODQwMDY3NjcyODJfODg2QkE1NDYtODY1OC00NDkyLUIyM0QtQ0QyRTgzQUJCRjczLnBuZw==.png](https://pic.leetcode-cn.com/84c1f19a88acd726b03bbb42e682b035b82afab5abcdc9942d1de33f076ab8fd-QzpcVXNlcnNcSkhabWFcQXBwRGF0YVxSb2FtaW5nXERpbmdUYWxrXDYyMDE5ODQ1OF92MlxJbWFnZUZpbGVzXDE1ODQwMDY3NjcyODJfODg2QkE1NDYtODY1OC00NDkyLUIyM0QtQ0QyRTgzQUJCRjczLnBuZw==.png)
```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)>>1):
            s[i],s[~i]=s[~i],s[i]
```
s[~i]代表s的倒数第i个元素