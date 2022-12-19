### 解题思路
这道题目的 code 非常不舒服。

代码写得很差。中间的 while 循环一团糟。如果能写好一点就好了。

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        n = len(s)
        if n<=1:
            return s
        A = {'a','A', 'e', 'E', 'i', 'I', 'o','O', 'u', 'U'}
 
        s_l = [x for x in s]
        i, j = 0, n-1
        while i<j:  #样例 hello 过不去
            while i<j and s_l[i] not in A:  # 不加 i<j 会炸掉
                i += 1
            if i>=j:
                break
            while i<j and s_l[j] not in A: # 不加 i<j 可能会炸掉
                j -= 1
            if i>=j:
                break

            s_l[i], s_l[j] = s_l[j], s_l[i]
            i += 1
            j -= 1
         
        return "".join(s_l)
```