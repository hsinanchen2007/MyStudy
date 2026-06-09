
### 一句话思路
将 DP 数组 `d[i][j]` 理解为以第 $i$ 和 第 $j$ 个字母为手指终点的手指累计最小移动距离

### 思路
对于任意的输入字符串 `word`，在输入完毕时，必然有至少一根手指停留在字符串最后一个字符上 **（请思考一下为什么说是至少）** 。因此，对于两指输入的最小距离，可以转化为**求所有以最后一个字符为终点的移动距离中的最小值**。

接下来是如何得到这个值，我们可以使用 DP （或者同理如其他题解所说的从上而下的递归+记忆化方法）来解决问题。考虑一个 DP 数组 `d[i][j]`，其中 $i \geq j$，表示以 `word` 第 $i$ 和第 $j$ 个字符为手指终点的最小移动距离。特别地，$d[i][i]$ 表示仅使用一根手指移动的情况。

对于每一个 $i$ ，和前一状态 $i-1$ 之间存在四条转移方程：
- 将之前放在第 $k$ 个字母上的手指移动到第 $i$ 个字母上，此时新的双指位置为 $i$ 和 $i-1$
    - $d[i][i-1] = d[i-1][k] + dist(k, i)$ 
- 将之前放在第 $i-1$ 个字母上的手指移动到第 $i$ 个字母上，此时新的双指位置为 $i$ 和 $k$
    - $d[i][k] = d[i-1][k] + dist(i-1, i)$ 
- 之前仅使用一根手指的情况下，将第二根手指直接移动到第 $i$ 个字母上 
    - $d[i][i-1] = d[i-1][i-1] + 0$
- 依然只使用一根手指
    - $d[i][i] = d[i-1][i-1] + dist(i-1, i)$ 

转移顺序为从左到右，转移基态为 
- $d[0][0] = 0$ 
- $d[1][0] = 0$ 
- $d[1][1] = dist(0, 1)$ 

### 代码
耗时 15 ms

```java
class Solution {
    public int minimumDistance(String word) {
        int len = word.length();
        char[] chars = word.toCharArray();  // 调用 charAt 方法并不是痛点，所以此处转换为 char 数组意义不大
        
        int[][] d = new int[len][len];      // DP Array
        int[][] dist = new int[len][len];   // dist Array，用 tabular 空间换时间避免重复计算，
                                            // 但此步意义也不明显，因为重复计算并不频繁，可省略
        for (int i = 0; i < len; i++)
            for (int j = i+1; j < len; j++)
                dist[i][j] = distance(chars[i]-'A', chars[j]-'A');
        
        for (int i = 1; i < len; i++) {
            Arrays.fill(d[i], Integer.MAX_VALUE);   // 初始化
            
            for (int j = 0; j < i-1; j++) {
                // 将原先放在第 i-1 个字母上的手指移到 i 上，此时两根手指分别以第 i, j 个字母为终点 
                d[i][j] = Math.min(d[i][j], d[i-1][j] + dist[i-1][i]);      
                // 将原先放在第 j 个字母上的手指移到 i 上，此时两根手指分别以第 i, i-1 个字母为终点 
                d[i][i-1] = Math.min(d[i][i-1], d[i-1][j] + dist[j][i]);    
            }
            
            // 如果此前仅使用了一根手指，可以将第二根手指放在第 i 个字母上，不消耗步数；可以将消耗理解为 `d[i-1][i-1] + 0`
            d[i][i-1] = Math.min(d[i][i-1], d[i-1][i-1]);
            // 依旧仅使用一根手指
            d[i][i] = d[i-1][i-1] + dist[i-1][i];   
        }
    
        int ret = Integer.MAX_VALUE;
        for (int i = 0; i < len-1; i++)
            ret = Math.min(ret, d[len-1][i]);   // 无需考虑 d[len-1][len-1]，必然不是最优
            
        return ret;
    }
    
    private int distance(int a, int b) {
        int x1 = a / 6, y1 = a - 6*x1;
        int x2 = b / 6, y2 = b - 6*x2;

        return Math.abs(x2-x1) + Math.abs(y2-y1);
    }
    
    
}
```

### 性能分析
- 时间复杂度：$O(n^2)$
- 空间复杂度：$O(n^2)$