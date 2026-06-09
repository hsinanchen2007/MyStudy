这题第一眼看到就是搜索。有几个剪枝的点：

1. `F.length >= 3` 说明结果数组最少元素都要是 3 个，那么就前两个数肯定有一个是小于等于 `len / 3 + 1` 的。这个你可以用反证法来证明，假设前两个数的位数都是 `len / 3 + 1` 位，那么第三个数位数肯定小于等于 `len / 3 - 2`，那么就说明第三个数肯定比前两个数中任意一个数小，这不满足正整数 Fib 数列的规律；
2. 前置零是无效的。每一个分段构成的 `num` 如果位数超过 1 位，判断 `num[0] == 0` 做一次剪枝；
3. 最坑爹的一点就是，`0 <= F[i] <= 2^31 - 1`，所以在反复遍历的时候判断一次就好了。

> 为什么说 3 坑爹，因为我开始以为是为了防止 `int` 太大而造成溢出，从而减少答题者处理成本。而实际上，这是一个 WA 的 case，其中有一组数据是 "539834657215398346785398346991079669377"，并且是满足 Fib 数列拆分的。

```
539834657 2
1
[539834657, 2]
10
39
539834657 21
5
[539834657, 21]
11
39
[539834657, 21, 539834678]
20
39
[539834657, 21, 539834678, 539834699]
29
39
[539834657, 21, 539834678, 539834699, 1079669377]
39
39
```

```python
class Solution:
    def __init__(self):
        self.S = ""
        self.debug = False
        self.SBSB = 2 ** 31 - 1
    
    def dfs(self, na: int, nb: int, st: int) -> list:
        res = [na, nb]
        while True:
            if self.debug:
                print(res)
                print(st)
                print(len(self.S))
            if st == len(self.S):
                return res
            nn = na + nb
            nns = str(nn)
            l = len(nns)
            if st + l > len(self.S): 
                return []
            nxt = self.S[st: st + l]
            if int(nxt) == nn and int(nxt) >= 0 and int(nxt) <= self.SBSB:
                res.append(int(nxt))
                na = nb
                nb = int(nxt)
                st = st + l
            else:
                return []    
        
    def splitIntoFibonacci(self, S: str) -> List[int]:
        self.S = S
        for i in range(1, len(S) // 3 + 2):
            sa = S[0: i]
            if sa[0] == '0' and len(sa) > 1:
                continue
            for j in range(1, len(S) - len(sa) - 1):
                sb = S[i:i + j]
                # 根据位数剪枝
                if len(S) - len(sa) - len(sb) < len(sb): 
                    continue
                # 首位为 0 剪枝    
                if sb[0] == '0' and len(sb) > 1:
                    continue    
                na, nb, pos = int(sa), int(sb), i + j
                # if na == 539834657:
                    #self.debug = True
                
                if self.debug:
                    print(na, nb)
                    print(S[i + j])
                res = self.dfs(na, nb, i + j)
                if len(res) > 2:
                    return res 
        return []        

```