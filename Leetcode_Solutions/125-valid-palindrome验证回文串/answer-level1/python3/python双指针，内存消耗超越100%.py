![批注 2020-02-25 201806.png](https://pic.leetcode-cn.com/9183ecbc9bd1b1211241b682e1d1470ba07c9e8f8c470ac78621f8f3d4f1c524-%E6%89%B9%E6%B3%A8%202020-02-25%20201806.png)
```
if len(s)==0: return True
        i, j = 0, len(s)-1
        while i<j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].lower() != s[j].lower():
                    return False
                else:
                    i += 1
                    j -= 1
            if not s[i].isalnum():
                i += 1
            if not s[j].isalnum():
                j -= 1
        return True
```

