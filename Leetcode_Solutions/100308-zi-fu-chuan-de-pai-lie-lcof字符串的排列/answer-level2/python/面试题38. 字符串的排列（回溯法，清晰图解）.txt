#### 解题思路：

- **排列方案数量：** 对于一个长度为 $n$ 的字符串（假设字符互不重复），其排列共有 $n \times (n-1) \times (n-2) … \times 2 \times 1$ 种方案。
- **排列方案的生成方法：** 根据字符串排列的特点，考虑深度优先搜索所有排列方案。即通过字符交换，先固定第 $1$ 位字符（ $n$ 种情况）、再固定第 $2$ 位字符（ $n-1$ 种情况）、... 、最后固定第 $n$ 位字符（ $1$ 种情况）。

![Picture1.png](https://pic.leetcode-cn.com/dc4659dbda6d54f50a8c897647fb7c52e2b8200e741c4d6e25306dfe51f93bb6-Picture1.png){:width=500}

- **重复方案与剪枝：** 当字符串存在重复字符时，排列方案中也存在重复方案。为排除重复方案，需在固定某位字符时，保证“每种字符只在此位固定一次”，即遇到重复字符时跳过。从 DFS 角度看，此操作称为“剪枝”。

![Picture2.png](https://pic.leetcode-cn.com/edbbe4db611791ca63e582e8b0c754261e8d7464edace38420ce3087eb96d9a5-Picture2.png){:width=500}

##### 递归解析：

1. **终止条件：** 当 $x = len(c) - 1$  时，代表所有位已固定（最后一位只有 $1$ 种情况），则将当前组合 `c` 转化为字符串并加入 `res`，并返回；
2. **递推参数：** 当前固定位 $x$ ；
3. **递推工作：** 初始化一个 Set ，用于排除重复的字符；将第 $x$ 位字符与 $i \in [x, len(c)]$ 字符分别交换，并进入下层递归；
   1. **剪枝：** 若 $c[i]$ 在 Set​ 中，代表其是重复字符，因此“剪枝”；
   2. 将 $c[i]$ 加入 Set​ ，以便之后遇到重复字符时剪枝；
   3. **固定字符：** 将字符 $c[i]$ 和 $c[x]$ 交换，即固定 $c[i]$ 为当前位字符；
   4. **开启下层递归：** 调用 $dfs(x + 1)$ ，即开始固定第 $x + 1$ 个字符；
   5. **还原交换：** 将字符 $c[i]$ 和 $c[x]$ 交换（还原之前的交换）；

> 下图中 `list` 对应文中将字符串 `s` 转为列表的 `c` 。

<![Picture3.png](https://pic.leetcode-cn.com/03ef0cdb9aa977a26d66bac91c5aa4b8bcaf612c7a90d47afd5b2774d2e7c63f-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/23190801938902294ce223fdec6e2b14b57c0050341dd2cd9909e5388d4fa4b6-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/5c71c17efa89114eee4d31678af45cefac82b0fad2a78c3887662463d10cfc83-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/a9d78bf7bdd7356d5c87392b731a98dc7012bb07c8a2bcde983abe7957bfde0a-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/546998a83a0832f3eed25ee69d1186ebcc23d238d0f45892feb02afd02bcaae9-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/405326ab9eccefe10fa18255704d0820ade5dd9b328a73b061634cfde8d059bd-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/59159c4b72187e1a4a52bebcd2b225a602badba483ef563114c9b1a7d694b0bf-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/d0e959953dcf93557e14cc037a0a1b62e60b3c0e3e38ca6b01f8acd06d4e5ea4-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/f34d4f405b2fb355fcad12d2c7818716b02ff78504e82be2343a1f7e75424eb3-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/58700b824790d48fe907fa6740f53d747e01cdd6d9c4b01cd60cad0135278d99-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/83dabfa3d9c04601ee53989ba410069153e841403584739140a499e8c4f3d8e1-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/337e2cdad2bcf4fd801ae2d4e5ab8a1c3ef8f30008d2b0fadde6aad7c87fd640-Picture14.png),![Picture15.png](https://pic.leetcode-cn.com/ba18b921c78d58e1f1c6fa55a939cbd4a2a9652c31f6c3088219565b70dc3b19-Picture15.png),![Picture16.png](https://pic.leetcode-cn.com/25d13a660956672f9d3b3a1fa87ddac8194fda6e58d7c354799d6421c61fab61-Picture16.png),![Picture17.png](https://pic.leetcode-cn.com/3efd2969a04b993303229c7e58a635fe3d018a84086b36e486f458d8f87d54cf-Picture17.png)>

##### 复杂度分析：

- **时间复杂度 $O(N!)$ ：** $N$ 为字符串 `s` 的长度；时间复杂度和字符串排列的方案数成线性关系，方案数为 $N \times (N-1) \times (N-2) … \times 2 \times 1$ ，因此复杂度为 $O(N!)$ 。
- **空间复杂度 $O(N^2)$ ：** 全排列的递归深度为 $N$ ，系统累计使用栈空间大小为 $O(N)$ ；递归中辅助 `Set` 累计存储的字符数量最多为 $N + (N-1) + ... + 2 + 1 = (N+1)N/2$ ，即占用 $O(N^2)$ 的额外空间。

#### 代码：

```python []
class Solution:
    def permutation(self, s: str) -> List[str]:
        c, res = list(s), []
        def dfs(x):
            if x == len(c) - 1:
                res.append(''.join(c)) # 添加排列方案
                return
            dic = set()
            for i in range(x, len(c)):
                if c[i] in dic: continue # 重复，因此剪枝
                dic.add(c[i])
                c[i], c[x] = c[x], c[i] # 交换，固定此位为 c[i] 
                dfs(x + 1) # 开启固定第 x + 1 位字符
                c[i], c[x] = c[x], c[i] # 恢复交换
        dfs(0)
        return res
```

```java []
class Solution {
    List<String> res = new LinkedList<>();
    char[] c;
    public String[] permutation(String s) {
        c = s.toCharArray();
        dfs(0);
        return res.toArray(new String[res.size()]);
    }
    void dfs(int x) {
        if(x == c.length - 1) {
            res.add(String.valueOf(c)); // 添加排列方案
            return;
        }
        HashSet<Character> set = new HashSet<>();
        for(int i = x; i < c.length; i++) {
            if(set.contains(c[i])) continue; // 重复，因此剪枝
            set.add(c[i]);
            swap(i, x); // 交换，固定此位为 c[i] 
            dfs(x + 1); // 开启固定第 x + 1 位字符
            swap(i, x); // 恢复交换
        }
    }
    void swap(int a, int b) {
        char tmp = c[a];
        c[a] = c[b];
        c[b] = tmp;
    }
}
```