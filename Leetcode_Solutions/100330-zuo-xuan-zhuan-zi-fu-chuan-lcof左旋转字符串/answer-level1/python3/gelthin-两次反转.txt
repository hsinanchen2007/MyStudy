### 解题思路
基本同习题 [189. 旋转数组-gelthin-经典题-代码没写好](https://leetcode-cn.com/problems/rotate-array/solution/gelthin-jing-dian-ti-by-gelthin-2/)


目前还只会两次反转的方法，有一步到位的方法，但写起来复杂，易错。还没有去学习写。




### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        def swap(s_l, p, q):  ## 这里 s_l 相当于是传引用
            i, j = p, q
            while i<j:
                s_l[i], s_l[j] = s_l[j], s_l[i]
                i += 1
                j -= 1

        s_l = list(s)
        leng = len(s_l)
        n = n % leng
        swap(s_l, 0, leng-1)
        swap(s_l, 0, leng-n-1)
        swap(s_l, leng-n, leng-1)
        return "".join(s_l)

```