关键是要意识到只要判断两次就够了：`A * mult`和`A*mult+A[:len(B)-1]`，`mult`是使得`len(A) >= len(B)`的最小的整数。因为如果A比B短，B肯定不是它的子串。

为什么只看这两个就够了？看下面的图解。

```text
A*mult ---------- 
B      -------
1. 滑动B之后，后面超出的部分无法比较
A*mult ----------???
B            -------
2. 最多检查超出的len(B)-1个元素，因为超出len(B)的时候，相当于又在看A*mult的开头了
A*mult ----------??????
B               -------
3. 让A' = A*mult + A[:len(B)-1]
            len(B)-1 q
A' ----------|------|----
B           -------
4. 可以发现，从q开始的子串，已经在前面一部分从q'开始的字符串中出现过了。由于在前面，我们已经检查过
   从A'任何位置开始的字符串，再往后的检查都只是重复。
   我这里多加了一段，看得更明白
          q'         q
A' ----------|----------|----------
B                    -------
```
```python
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        # 如果A里字母种类少于B，再怎么重复也没法变出来，直接-1
        if len(set(A)) < len(set(B)): return -1
        mult = math.ceil(len(B)/len(A))
        A = A * mult
        if B in A:
            return mult
        if B in A+A[:len(B)-1]:
            return mult+1
        return -1
```

