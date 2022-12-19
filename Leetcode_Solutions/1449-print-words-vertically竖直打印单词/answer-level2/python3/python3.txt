### 解题思路
最直白的思路
### 代码

```python
class Solution:
    def printVertically(self, s: str) -> List[str]:
        tmp = list(s.split(" "))
        count = 0
        for i in tmp:
            count=max(count,len(i))
        res = ['' for _ in range(count)]
        for i in tmp:
            for j in range(count):
                if j<len(i):
                    res[j]+=i[j]
                else:
                    res[j]+=" "
        for i in range(len(res)):
            while res[i][-1]==" ":
                res[i]=res[i][:-1]
        return res
```
![image.png](https://pic.leetcode-cn.com/508da0e89e172e6b6671f325192dccc3a4d2062f67b8a44828364abf209671bb-image.png)
