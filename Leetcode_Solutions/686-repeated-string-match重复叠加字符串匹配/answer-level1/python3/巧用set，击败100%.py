![686.jpg](https://pic.leetcode-cn.com/a9c80571697ac14347198a226503bf412b7c19f80d531253aefb62efd94b4dd5-686.jpg)

利用set得到A、B的元素集合，当A中元素个数小于B中元素个数时，直接返回-1
代码如下：

```
class Solution:
                def repeatedStringMatch(self, A: str, B: str) -> int:
                    if len(set(A))<len(set(B)):
                        return -1
                    i = max(1, len(B)//len(A))
                    # print(i)
                    while True:
                        C = A*i
                        if B in C:
                            return i
                        if len(C)>=2*len(B) and i>1:
                            return -1
```
          