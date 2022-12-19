![image.png](https://pic.leetcode-cn.com/d12aeb6e47efec456db8970eb1f3a1d01a9a28a2548558914d85343a61728e97-image.png)

T元素按S序加桶，没加进桶的就先加进ans，最后再把桶里的元素按数量输入进ans，时间复杂度$O(N)$

```python []
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        d = {c: 0 for c in S}
        ans = ''
        for c in T:
            if c in d:
                d[c] += 1
            else:
                ans += c
        for c in d:
            ans += c * d[c]
        return ans
```

![image.png](https://pic.leetcode-cn.com/c605b4d8df2c033b5fbf0817c06c942b3c52bee439e5b09f0826733acfd9ad04-image.png)

按S序做顺序字典，不在S里的字母顺序为-1，然后直接用系统快排，时间复杂度$O(NlogN)$

```python []
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        d = {**{chr(i): -1 for i in range(ord('a'), ord('z') + 1)}, **{c: i for i, c in enumerate(S)}}
        return ''.join(sorted(T, key = lambda x: d[x]))
```

计算时间复杂度的时候，S最大才是26，所以可以忽略了，但因为T的长度也不大，所以基本没啥区别，估计暴力$O({N}^{2})$算法也能过。