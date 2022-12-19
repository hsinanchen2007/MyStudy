**N次的输出，需要进行N-1次循环，每次对上次字符进行访问和分析，累加得到字符串**

```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        else:
            a = "1"
            for i in range(1,n):
                res = ""
                cnt = 1
                for j in range(1,len(a)):
                    if a[j] == a[j-1]:
                        cnt += 1
                    else:
                        res += str(cnt) + a[j-1]
                        cnt = 1
                res += str(cnt) + a[-1]
                a = res
            return res
```
