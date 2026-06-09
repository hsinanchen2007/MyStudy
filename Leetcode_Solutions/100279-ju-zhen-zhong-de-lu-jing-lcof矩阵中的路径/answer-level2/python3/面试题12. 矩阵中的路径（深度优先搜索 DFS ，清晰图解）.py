#### 解题思路：

> 本问题是典型的矩阵搜索问题，可使用 **深度优先搜索（DFS）+ 剪枝** 解决。

##### **算法原理：** 

- **深度优先搜索：** 可以理解为暴力法遍历矩阵中所有字符串可能性。DFS 通过递归，先朝一个方向搜到底，再回溯至上个节点，沿另一个方向搜索，以此类推。
- **剪枝：** 在搜索中，遇到 `这条路不可能和目标字符串匹配成功` 的情况（*例如：此矩阵元素和目标字符不同、此元素已被访问）*，则应立即返回，称之为 `可行性剪枝` 。

##### **算法剖析：**

- **递归参数：** 当前元素在矩阵 `board` 中的行列索引 `i` 和 `j` ，当前目标字符在 `word` 中的索引 `k` 。
- **终止条件：**
  1. **返回 $false$ ：** ① 行或列索引越界 **或** ② 当前矩阵元素与目标字符不同 **或** ③ 当前矩阵元素已访问过 *（③ 可合并至 ② ）* 。
  2. **返回 $true$ ：** 字符串 `word` 已全部匹配，即 `k = len(word) - 1` 。
- **递推工作：**
  1. **标记当前矩阵元素：** 将 `board[i][j]` 值暂存于变量 `tmp` ，并修改为字符 `'/'` ，代表此元素已访问过，防止之后搜索时重复访问。
  2. **搜索下一单元格：** 朝当前元素的 **上、下、左、右** 四个方向开启下层递归，使用 `或` 连接 *（代表只需一条可行路径）* ，并记录结果至 `res` 。
  3. **还原当前矩阵元素：** 将 `tmp` 暂存值还原至 `board[i][j]` 元素。
- **回溯返回值：** 返回 `res` ，代表是否搜索到目标字符串。

> 图解中，从每个节点 DFS 的顺序为：下、上、右、左。

<![Picture1.png](https://pic.leetcode-cn.com/5686e97e87f4a65b15add619cf4a65f2a88362ea4f3f60965997a89f7e88fd5e-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/d1c30be864eed54b4d0d70098e05c32186e1f947106f0e536d362d663208db92-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/1387b7b367a170dddf46e4161308e72f75e02b024f9a6d05695b443b60d08ffa-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/cb6e8b8c34bd6df5aa64635a0c37fc83b0034a8a373251d9f7e140d54554a795-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/c06df9a503dadfca9402a64d2d241a073e363229ecd8e1a1ca094e32379fad8b-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/53a504341509d1143bf84d600642660f78c0c0db28899fa49df98a039184a80a-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/78a4d22d3196d8f24a2c8ef5812bfb765650a2e72ceafcfa08bc70c26ab14a51-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/ace98f3a3e06bebf158cc7ab3450a3e60afd2f8f250553d901311c3339f9c58d-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/b19e597c6a41e63cf6a6c5bb47cf3f4ea42bde840d4c53446bfed4b593a9a872-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/8f3e75419871d2c087f8b66e19fdf24341a4e0c3c3a7bcd9305562dc73096b23-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/71357c63c0bb29011fd4a8ab48445e734d4cf36cdfb94b13d976246e9defa666-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/8e48fb9b03070d4c4c73b0135ad21acdde35df20dc67870b2f8ea2e12bccf9a1-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/72f9175d1898a85390416ff5d7b35d3f1751af979b4d918ae912a5ea88032fcf-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/3f54dd07f8cc4973e9770d0e4b9df69abfce80716db76ffc6c0824140f4625da-Picture14.png),![Picture15.png](https://pic.leetcode-cn.com/bb6560a7f7dc481609c7a4db3c0eaab4ec01d42bbe90bbe3e80e9142ad9b2c91-Picture15.png),![Picture16.png](https://pic.leetcode-cn.com/99b9924fe7d4ef206d5fe22d357f75788dc899ccca99d5f757ef1499d8ccc188-Picture16.png),![Picture17.png](https://pic.leetcode-cn.com/947eeb47471b1e84e30a53484a78808060f1587728aed3fa73305d5d3f548804-Picture17.png),![Picture18.png](https://pic.leetcode-cn.com/213e1f424f47d6e419a7d79e1a2ca74aa24e53bb750a8ed48e7ccd73d5bc00b8-Picture18.png)>

##### 复杂度分析： 

> $M, N$ 分别为矩阵行列大小， $K$ 为字符串 `word` 长度。

- **时间复杂度 $O(3^KMN)$ ：** 最差情况下，需要遍历矩阵中长度为 $K$ 字符串的所有方案，时间复杂度为 $O(3^K)$；矩阵中共有 $MN$ 个起点，时间复杂度为 $O(MN)$ 。
    - **方案数计算：** 设字符串长度为 $K$ ，搜索中每个字符有上、下、左、右四个方向可以选择，舍弃回头（上个字符）的方向，剩下 $3$ 种选择，因此方案数的复杂度为 $O(3^K)$ 。
- **空间复杂度 $O(K)$ ：** 搜索过程中的递归深度不超过 $K$ ，因此系统因函数调用累计使用的栈空间占用 $O(K)$ （因为函数返回后，系统调用的[栈空间会释放](https://leetcode-cn.com/explore/orignial/card/recursion-i/259/complexity-analysis/1223/)）。最坏情况下 $K = MN$ ，递归深度为 $MN$ ，此时系统栈使用 $O(MN)$ 的额外空间。

#### 代码：

```python []
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, k):
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[k]: return False
            if k == len(word) - 1: return True
            tmp, board[i][j] = board[i][j], '/'
            res = dfs(i + 1, j, k + 1) or dfs(i - 1, j, k + 1) or dfs(i, j + 1, k + 1) or dfs(i, j - 1, k + 1)
            board[i][j] = tmp
            return res

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0): return True
        return False
```

```java []
class Solution {
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(dfs(board, words, i, j, 0)) return true;
            }
        }
        return false;
    }
    boolean dfs(char[][] board, char[] word, int i, int j, int k) {
        if(i >= board.length || i < 0 || j >= board[0].length || j < 0 || board[i][j] != word[k]) return false;
        if(k == word.length - 1) return true;
        char tmp = board[i][j];
        board[i][j] = '/';
        boolean res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
                      dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
        board[i][j] = tmp;
        return res;
    }
}
```