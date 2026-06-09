### 解题思路

![image.png](https://pic.leetcode-cn.com/8881b6282b3f1047f467ebd77e924309b6bda36e97a04e24dd31fdf8ee390e02-image.png)

### 代码

```python3
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        mem = {}
        if k < 0 or k > hi - lo + 1 or lo > hi:
            return
        
        def core(n):
            if n == 1:
                return 1
            if n in mem:
                return mem[n]
            if n % 2 == 0:
                mem[n] = 1 + core(n // 2)
                return mem[n]
            if n % 2 == 1:
                mem[n] = 1 + core(3 * n + 1)
                return mem[n]
        
        res_dict = {}
        for i in range(lo, hi+1):
            res_dict[i] = core(i)
        
        ord_dict=sorted(res_dict.items(),key=lambda x:x[1],reverse=False)
        res = []
        for i, (key, val) in enumerate(ord_dict):
            if i + 1 == k:
                return key
            
```