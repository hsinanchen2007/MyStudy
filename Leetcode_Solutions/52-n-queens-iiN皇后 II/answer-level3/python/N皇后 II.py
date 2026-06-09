#### 直观想法

这个问题是一个经典的问题，感受解法的优雅性很重要。

第一个想法是使用蛮力法，意味着生成在棋盘上放置 `N` 个皇后的所有可能的情况，并且检查是否保证没有皇后可以互相攻击。这意味着 $\mathcal{O}(N^N)$ 的时间复杂度，因此我们必须考虑优化。

下面是两个有用的编程概念。

> 第一个叫做 _约束编程_. 

它的基本含义是在放置每个皇后以后增加限制。当在棋盘上放置了一个皇后后，立即排除当前行，列和对应的两个对角线。该过程传递了 _约束_ 从而有助于减少需要考虑情况数。


![51_pic.png](https://pic.leetcode-cn.com/e67ed217a00038ed292ae8cb89c1a8492c7a49e33ec17f633f41c4ece77d6c2c-51_pic.png){:width=500px}

> 第二个叫做 _回溯法_.

我们来想象一下，当在棋盘上放置了几个皇后且不会相互攻击。但是选择的方案不是最优的，因为无法放置下一个皇后。此时我们该怎么做？_回溯_。意思是回退一步，来改变最后放置皇后的位置并且接着往下放置。如果还是不行，再 _回溯_。


![51_backtracking_.png](https://pic.leetcode-cn.com/610377e670ee1d4184c0475edee789139d8fe9ebeb07df267e9c54fbd31c449e-51_backtracking_.png){:width=500px}
<br />
<br />
---
#### 方法1：回溯

在建立算法之前，我们来考虑两个有用的细节。

> 一行只可能有一个皇后且一列也只可能有一个皇后。

这意味着没有必要再棋盘上考虑所有的方格。只需要按列循环即可。

> 对于所有的主对角线有 `行号 + 列号 = 常数`，对于所有的次对角线有 `行号 - 列号 = 常数`.  

这可以让我们标记已经在攻击范围下的对角线并且检查一个方格 `(行号, 列号)` 是否处在攻击位置。

![51_diagonals.png](https://pic.leetcode-cn.com/332b878ebcd261a71f5f85cb4e23685d42b37685112f562e2844079748e63cd0-51_diagonals.png){:width=500px}

现在已经可以写回溯函数 `backtrack(row = 0)`.

* 从第一个 `row = 0` 开始. 
* 循环列并且试图在每个 `column` 中放置皇后.

    * 如果方格 `(row, column)` 不在攻击范围内
        
        * 在 `(row, column)` 方格上放置皇后。
        * 排除对应行，列和两个对角线的位置。
        * If 所有的行被考虑过，`row == N`
            * 意味着我们找到了一个解
        * Else
            * 继续考虑接下来的皇后放置 `backtrack(row + 1)`.
        * 回溯：将在 `(row, column)` 方格的皇后移除.
        
下面是上述算法的一个直接的实现。

<![image.png](https://pic.leetcode-cn.com/52211da4b8a1f47c27ae6e35007076b348f6f1024d57fe9667aa5106d162e6d0-image.png),![image.png](https://pic.leetcode-cn.com/27e7a515e750f811aaf0bac1e3afa22a3fe8e0b11557d40535bf9925cc3afea8-image.png),![image.png](https://pic.leetcode-cn.com/21f2476d73dbad6964e7d07cabd10e94d752047b3618a105493e347cd1bde9ec-image.png),![image.png](https://pic.leetcode-cn.com/b0ebda14dfaffe8844f6af40737655692393824f1a0a3645db3de9158df8c69f-image.png),![image.png](https://pic.leetcode-cn.com/8e456bc49ec64db73ba439efd713ffdb4e86380eb5a36afd3f22ea8b43143863-image.png),![image.png](https://pic.leetcode-cn.com/25fb91fe5064f3fae9b78401279617254fa78420a8c5c561cf8394d761c0b843-image.png),![image.png](https://pic.leetcode-cn.com/8e444442f07829b093caab45cbe8a848dab3a6aac45836a0485c6cc37ccf1f35-image.png),![image.png](https://pic.leetcode-cn.com/5e230694c372dcd9afd29077e6e4d5d2234862867f46d29ffaef92c80832e447-image.png),![image.png](https://pic.leetcode-cn.com/449c5102360034bcb98c127251e5c1b5b570b886e496b6f7a3f452396ff9c73a-image.png),![image.png](https://pic.leetcode-cn.com/350f2a136e4d4df63b997efc9fe7a4e4ef4049758e07f27ea848b655a6e640f5-image.png),![image.png](https://pic.leetcode-cn.com/152d6030fe0ebd5430f0bcfe243921a51a360c35e0d1f70aecb86bc2cce355f9-image.png),![image.png](https://pic.leetcode-cn.com/3b9bbf4b3240cea52d7fc0a526738d43c58e3ab82e65ff5966bc858d5f3cc13e-image.png),![image.png](https://pic.leetcode-cn.com/de8d9e3402a2821359657b59e4b91ebe17ec157afa7811b8ffcc29ea28e83460-image.png),![image.png](https://pic.leetcode-cn.com/bdd95149095c195ce0416d7405ff3fc5a9e90d24c7dccfcca26eb735c768ea37-image.png),![image.png](https://pic.leetcode-cn.com/dde66b1426f0dc28dca6bd38df2186958efe202814cef991be63a6ee058a5b5a-image.png),![image.png](https://pic.leetcode-cn.com/e027dc798a86f1e7998d0dc1027758df10d309b45261d70705e6b2cbcc54ce65-image.png),![image.png](https://pic.leetcode-cn.com/18766bfdae2d8d1cc349afd4061e8cd3c784bbde12dfb5353344e5c5309b3b32-image.png),![image.png](https://pic.leetcode-cn.com/9718b7be96e0bbf2cac35b8c056d01e232d6553ad419e97957e3677fe43d8d0f-image.png),![image.png](https://pic.leetcode-cn.com/42a87517441171c8af1d6c3a90655a3e7e4010a06d957ec52b9e1037cc8707fc-image.png),![image.png](https://pic.leetcode-cn.com/2ecd4a37e8ed16ed0b0ba706b2cee74856c08e41b56ba9fbad4cb7fcd5eac5e5-image.png),![image.png](https://pic.leetcode-cn.com/57517bd4590e41648c0681fab9557492809b7bc8deb3370f3e8b2e08bd857bcb-image.png),![image.png](https://pic.leetcode-cn.com/84fae14fa37f50233ff523abe20d491d099b9805ae76f862791fe77b6a9787ae-image.png),![image.png](https://pic.leetcode-cn.com/fd4a0fb8059a7d4acfda8cd13d69c24fe272d9b63057e60864f39ce8da942710-image.png),![image.png](https://pic.leetcode-cn.com/244b43d34ae2596a8a097b924e2bcd27156e690912b20fcd31be9ec5a9d4a0b6-image.png),![image.png](https://pic.leetcode-cn.com/81cd599bc695f3b72001ba3583aa0ddffe198d3e4fe622100e04cc5ed306933e-image.png),![image.png](https://pic.leetcode-cn.com/7ebd7eed1214f867a33492a057bfdfda646047a4bdbd071d5dd7080098b8b807-image.png),![image.png](https://pic.leetcode-cn.com/4e5e30aa4c6cdb539ac28fcb5d44a87e71968e59462ebfd2af27e8c8adf729ef-image.png),![image.png](https://pic.leetcode-cn.com/b4fc2c89ab5428e234605e6ca336be0e62393f73a35a239d269183d9195044cd-image.png),![image.png](https://pic.leetcode-cn.com/33073a60045448084481eb43486260e2dabbfa40420dce4cffd8172bc7cbf503-image.png),![image.png](https://pic.leetcode-cn.com/cd9f1d02c4e7ed0f1a3e6cc6097e988e0f6bc23f925e2567419c84f41f4680f2-image.png),![image.png](https://pic.leetcode-cn.com/9aa745674757e56a99da1fd3f77f3e121b7a138559429da3484b6a71d59713e5-image.png),![image.png](https://pic.leetcode-cn.com/f557695d9d2968c2e213aa786b8ee4d2453ffa7961293c450d92bfc998c686a2-image.png),![image.png](https://pic.leetcode-cn.com/96bb6d9c64bfb66411c8d5116f8a079b8090c5fb40e0ca9d81e125eee912cf91-image.png),![image.png](https://pic.leetcode-cn.com/a34dbf27e38b319264b6d04a90eea4dee10bd6f056c913a249a37c32915ecf62-image.png)>

```Java [Solution 2]
class Solution {
  public boolean is_not_under_attack(int row, int col, int n,
                                     int [] rows,
                                     int [] hills,
                                     int [] dales) {
    int res = rows[col] + hills[row - col + 2 * n] + dales[row + col];
    return (res == 0) ? true : false;
  }

  public int backtrack(int row, int count, int n,
                       int [] rows,
                       int [] hills,
                       int [] dales) {
    for (int col = 0; col < n; col++) {
      if (is_not_under_attack(row, col, n, rows, hills, dales)) {
        // place_queen
        rows[col] = 1;
        hills[row - col + 2 * n] = 1;  // "hill" diagonals
        dales[row + col] = 1;   //"dale" diagonals    

        // if n queens are already placed
        if (row + 1 == n) count++;
        // if not proceed to place the rest
        else count = backtrack(row + 1, count, n,
                rows, hills, dales);

        // remove queen
        rows[col] = 0;
        hills[row - col + 2 * n] = 0;
        dales[row + col] = 0;
      }
    }
    return count;
  }

  public int totalNQueens(int n) {
    int rows[] = new int[n];
    // "hill" diagonals
    int hills[] = new int[4 * n - 1];
    // "dale" diagonals
    int dales[] = new int[2 * n - 1];

    return backtrack(0, 0, n, rows, hills, dales);
  }
}
```

```Python [Solution 2]
class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def is_not_under_attack(row, col):
            return not (rows[col] or hills[row - col] or dales[row + col])
        
        def place_queen(row, col):
            rows[col] = 1
            hills[row - col] = 1  # "hill" diagonals
            dales[row + col] = 1  # "dale" diagonals
        
        def remove_queen(row, col):
            rows[col] = 0
            hills[row - col] = 0  # "hill" diagonals
            dales[row + col] = 0  # "dale" diagonals
        
        def backtrack(row = 0, count = 0):
            for col in range(n):
                if is_not_under_attack(row, col):
                    place_queen(row, col)
                    if row + 1 == n:
                        count += 1
                    else:
                        count = backtrack(row + 1, count)
                    remove_queen(row, col)
            return count
        
        rows = [0] * n
        hills = [0] * (2 * n - 1)  # "hill" diagonals
        dales = [0] * (2 * n - 1)  # "dale" diagonals
        return backtrack()
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N!)$. 放置第 1 个皇后有 `N` 种可能的方法，放置两个皇后的方法不超过 `N (N - 2)` ，放置 3 个皇后的方法不超过 `N(N - 2)(N - 4)` ，以此类推。总体上，时间复杂度为 $\mathcal{O}(N!)$ .
* 空间复杂度：$\mathcal{O}(N)$ . 需要保存对角线和行的信息。
<br />
<br />


---
#### 方法 2：使用 bitmap 回溯

如果你是在面试中 - 使用方法 `1`。

下面的算法有着相同的时间复杂度 $\mathcal{O}(N!)$。但是由于使用了[位运算](https://baike.baidu.com/item/%E4%BD%8D%E8%BF%90%E7%AE%97/6888804?fr=aladdin)，可以运行得更快。

感谢这个算法的提出者 [takaken](http://www.ic-net.or.jp/home/takaken/e/queen/).

为了便于理解该算法，下面的代码进行了逐步解释。

```Java [Solution 2]
class Solution {
  public int backtrack(int row, int hills, int next_row, int dales, int count, int n) {
    /** 
     row: 当前放置皇后的行号
     hills: 主对角线占据情况 [1 = 被占据，0 = 未被占据]
     next_row: 下一行被占据的情况 [1 = 被占据，0 = 未被占据]
     dales: 次对角线占据情况 [1 = 被占据，0 = 未被占据]
     count: 所有可行解的个数
     */

    // 棋盘所有的列都可放置，
    // 即，按位表示为 n 个 '1'
    // bin(cols) = 0b1111 (n = 4), bin(cols) = 0b111 (n = 3)
    // [1 = 可放置]
    int columns = (1 << n) - 1;

    if (row == n)   // 如果已经放置了 n 个皇后
      count++;  // 累加可行解
    else {
      // 当前行可用的列
      // ! 表示 0 和 1 的含义对于变量 hills, next_row and dales的含义是相反的
      // [1 = 未被占据，0 = 被占据]
      int free_columns = columns & ~(hills | next_row | dales);

      // 找到可以放置下一个皇后的列
      while (free_columns != 0) {
        // free_columns 的第一个为 '1' 的位
        // 在该列我们放置当前皇后
        int curr_column = - free_columns & free_columns;

        // 放置皇后
        // 并且排除对应的列
        free_columns ^= curr_column;

        count = backtrack(row + 1,
                (hills | curr_column) << 1,
                next_row | curr_column,
                (dales | curr_column) >> 1,
                count, n);
      }
    }

    return count;
  }
  public int totalNQueens(int n) {
    return backtrack(0, 0, 0, 0, 0, n);
  }
}
```

```Python [Solution 2]
class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def backtrack(row = 0, hills = 0, next_row = 0, dales = 0, count = 0):
            """
            :type row: 当前放置皇后的行号
            :type hills: 主对角线占据情况 [1 = 被占据，0 = 未被占据]
            :type next_row: 下一行被占据的情况 [1 = 被占据，0 = 未被占据]
            :type dales: 次对角线占据情况 [1 = 被占据，0 = 未被占据]
            :rtype: 所有可行解的个数
            """
            if row == n:  # 如果已经放置了 n 个皇后
                count += 1  # 累加可行解
            else:
                # 当前行可用的列
                # ! 表示 0 和 1 的含义对于变量 hills, next_row and dales的含义是相反的
                # [1 = 未被占据，0 = 被占据]
                free_columns = columns & ~(hills | next_row | dales)
                
                # 找到可以放置下一个皇后的列
                while free_columns:
                    # free_columns 的第一个为 '1' 的位
                    # 在该列我们放置当前皇后
                    curr_column = - free_columns & free_columns
                    
                    # 放置皇后
                    # 并且排除对应的列
                    free_columns ^= curr_column
                    
                    count = backtrack(row + 1, 
                                      (hills | curr_column) << 1, 
                                      next_row | curr_column, 
                                      (dales | curr_column) >> 1, 
                                      count)
            return count

        # 棋盘所有的列都可放置，
        # 即，按位表示为 n 个 '1'
        # bin(cols) = 0b1111 (n = 4), bin(cols) = 0b111 (n = 3)
        # [1 = 可放置]
        columns = (1 << n) - 1
        return backtrack()

```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N!)$. 
* 空间复杂度：$\mathcal{O}(N)$.