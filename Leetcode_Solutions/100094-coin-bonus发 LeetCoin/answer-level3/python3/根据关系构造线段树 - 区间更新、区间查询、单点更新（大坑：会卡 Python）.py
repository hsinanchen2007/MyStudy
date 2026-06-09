LC 上的题真的无力吐槽！！！

用 Python3 写线段树又会被卡时间，估计是官方没有测试过 python 的速度。。强烈建议运算量大的数据由于常数问题 + python 的运行效率放宽 Python 的运行时间。

解题思路大概就是：
1. 建树，然后遍历每一个节点来计算儿子节点的长度，做出节点的映射关系 L ，R，当做线段树区间更新的范围；
2. 构建线段树，要用 Lazy 做延迟更新，将区间更新优化到 logN。

以下是通过 cpp ac 的版本：

```cpp
#define maxn 50005
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define solve 1, cnt, 1 
const int mm = maxn * 4;

class Solution {
public:
    static const int mod = 1e9 + 7;
    int L[maxn], R[maxn], cnt;    
    vector<int> G[maxn];
    int sum[mm], add[mm];
    
    void dfs(int u) {
        ++ cnt; 
        L[u] = cnt;
        for (int v: G[u]) {
            dfs(v);
        }
        R[u] = cnt;
    }
    
    void build() {
        cnt = 0;
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        memset(sum, 0, sizeof(sum));
        memset(add, 0, sizeof(add));
    }
    
    void push_up(int rt) {
        sum[rt] = sum[rt * 2] % mod + sum[rt * 2 + 1] % mod;
    }
    
    void push_down(int rt, int m) {
        if (add[rt] != 0) {
            add[rt << 1] = add[rt << 1] % mod + add[rt] % mod;
            add[rt << 1 | 1] = add[rt << 1 | 1] % mod + add[rt] % mod;
            sum[rt << 1] = sum[rt << 1] % mod + add[rt] * (m - (m / 2)) % mod;
            sum[rt << 1 | 1] = sum[rt << 1 | 1] % mod + add[rt] * (m / 2) % mod;
            add[rt] = 0;
        }
    }
    
    void update_single(int p, int val, int l, int r, int rt) {
        if (l == r) {
            sum[rt] = sum[rt] % mod + val % mod;
            return;   
        }
        push_down(rt, r - l + 1);
        int m = (l + r) >> 1;
        if (p <= m) {
            update_single(p, val, lson);
        }
        else {
            update_single(p, val, rson);
        }
        push_up(rt);
    }
    
    void update_range(int L, int R, int c, int l, int r, int rt) {
        if (L <= l && r <= R) {
            add[rt] = add[rt] % mod + c % mod;
            sum[rt] = sum[rt] % mod + c * (r - l + 1) % mod; 
            return;
        }
        push_down(rt, r - l + 1);
        int m = (l + r) / 2;
        if (L <= m) {
            update_range(L, R, c, lson);
        }
        if (m < R) {
            update_range(L, R, c, rson);
        }
        push_up(rt);
    }
    
    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return sum[rt];
        }
        push_down(rt, r - l + 1);
        int m = (l + r) >> 1;
        int ret = 0;
        if (L <= m) {
            ret += query(L, R, lson);
        }
        if (m < R) {
            ret += query(L, R, rson);
        }
        return ret;
    }
    
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        build();
        for (auto l: leadership) {
            G[l[0]].push_back(l[1]);
        }
        dfs(1);
        vector<int> ans;
        for (auto op: operations) {
            switch (op[0]) {
                case 1:
                    update_single(L[op[1]], op[2], solve);
                    break;
                case 2:    
                    update_range(L[op[1]], R[op[1]], op[2], solve);
                    break;
                case 3:
                    int cur = query(L[op[1]], R[op[1]], solve) % mod;    
                    ans.push_back(cur);
                    break;
            }
        }
        return ans;
    }
};
```

---

还有一个 TLE 的 Python3 版本，代码一模一样。会卡在 48/50 这组数据上（@LeetCode中国 官方，可以来测试下 Python）。感觉用树状数组可过，主要是常数开销问题：

![image.png](https://pic.leetcode-cn.com/7921a776ea0ab621fdefe6b65a035c80289e90f32db708475ea844b91109162d-image.png)


```
48382
[[1
33002]
[33002
38285]
...
[3060... 1247159 more chars
```

```python
class Solution:
    
    def __init__(self):
        self.LEN = 50005
        self.G = [[] for _ in range(self.LEN)]
        self.cnt = 1 
        self.L, self.R = [0 for _ in range(self.LEN)], [0 for _ in range(self.LEN)]
        self.sum = [0 for _ in range(self.LEN * 4)]
        self.add = [0 for _ in range(self.LEN * 4)]
        self.MOD = 10 ** 9 + 7
        
    def dfs(self, u):
        self.cnt += 1
        self.L[u] = self.cnt
        for v in self.G[u]:
            self.dfs(v)
        self.R[u] = self.cnt
        
    def mod(self, num):
        return num % self.MOD    
        
    def push_up(self, rt: int):
        self.sum[rt] = self.sum[rt * 2] + self.sum[rt * 2 + 1]
        self.sum[rt] = self.mod(self.sum[rt])
        
    def push_down(self, rt: int, m: int):
        if (self.add[rt] != 0):
            self.add[rt << 1] += self.add[rt]
            self.add[rt << 1] = self.mod(self.add[rt << 1])
            
            self.add[rt << 1 | 1] += self.add[rt]
            self.add[rt << 1 | 1] = self.mod(self.add[rt << 1 | 1])
            
            self.sum[rt << 1] += self.add[rt] * (m - (m >> 1))
            self.sum[rt << 1] = self.mod(self.sum[rt << 1])
            
            self.sum[rt << 1 | 1] += self.add[rt] * (m >> 1)
            self.sum[rt << 1 | 1] = self.mod(self.sum[rt << 1 | 1])
            self.add[rt] = 0
            
    def update_single(self, p: int, val: int, l: int, r: int, rt):
        if l == r:
            self.sum[rt] += val 
            self.sum[rt] = self.mod(self.sum[rt])
            return
        self.push_down(rt, r - l + 1)
        m = (l + r) >> 1
        if p <= m:
            self.update_single(p, val, l, m, rt << 1)
        else :
            self.update_single(p, val, m + 1, r, rt << 1 | 1)    
        self.push_up(rt)    
            
    def update_range(self, L: int, R: int, c: int, l: int, r: int, rt: int):
        if L <= l <= r <= R:
            self.add[rt] += c
            self.add[rt] = self.mod(self.add[rt])
            self.sum[rt] += c * (r - l + 1)
            self.sum[rt] = self.mod(self.sum[rt])
            return
        self.push_down(rt, r - l + 1)
        m = (l + r) // 2
        if L <= m:
            self.update_range(L, R, c, l, m, rt << 1)    
        if m < R:
            self.update_range(L, R, c, m + 1, r, rt << 1 | 1)    
        self.push_up(rt)    
    
    def query(self, L: int, R: int, l: int, r: int, rt: int):
        if L <= l <= r <= R:
            return self.sum[rt]
        self.push_down(rt, r - l + 1)
        m, ret = (l + r) // 2, 0
        if L <= m:
            ret += self.query(L, R, l, m, rt << 1)      
            ret = self.mod(ret)
        if m < R:
            ret += self.query(L, R, m + 1, r, rt << 1 | 1)    
            ret = self.mod(ret)
        return ret    
        
    def bonus(self, n: int, leadership: List[List[int]], operations: List[List[int]]) -> List[int]:
        for l in leadership:
            self.G[l[0]].append(l[1])
        self.dfs(1)    
        ans = []
        for op in operations:
            if op[0] == 1:
                self.update_single(self.L[op[1]], op[2], 1, self.cnt, 1)
            elif op[0] == 2:
                self.update_range(self.L[op[1]], self.R[op[1]], op[2], 1, self.cnt, 1)
            elif op[0] == 3:
                ans.append(self.query(self.L[op[1]], self.R[op[1]], 1, self.cnt, 1) % self.MOD)    
        # print(ans)        
        return ans        
```