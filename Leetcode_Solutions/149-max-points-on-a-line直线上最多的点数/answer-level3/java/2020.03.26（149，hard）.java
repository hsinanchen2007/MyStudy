### 解题思路
本题可以分类记录，避免了多钟情况的讨论：

- 数学上一个点加一个斜率即可唯一确定一条直线（**点斜式**），用`max`来记录经过某个点的直线上最多的点
 
- 当确定一个点后，用这个点和其他点就可以求出一个**斜率**，而斜率相同的点就意味着在同一条直线上

- 如果遍历到有重复的点，用`duplicate`来记录重复点的个数
 
- 这里用到 `HashMap` 去**计数**，**斜率**作为 `key`，然后再遍历其他点，相同的 `key` 意味着在同一条直线上
 
- 如果**斜率是小数**，就用分数去表示，然后对分子分母求**最大公约数**再**约分**，最后将**分子 + "$" + "分母"**转化成字符串形式作为 `key` 传入`map`中返回即可。

### 代码

```java []
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n < 3) {
            return n;
        }
        // 记录一条直线上点的个数
        int ans = 0;
        // 从第1个数组开始循环遍历
        for (int i = 0; i < n; i++) {
            // 记录重复的点
            int duplicate = 0;
            // 记录经过当前点的直线中最多的点
            int max = 0;
            HashMap<String,Integer> map = new HashMap<>();
            // 从第 i + 1 + 1 个数组开始
            for (int j = i + 1; j < n; j++) {
                // 记录分子的差和分母的差
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                // 重复的点，则用 dup 记录
                if (x == 0 && y == 0) {
                    duplicate++;
                    continue;
                }
                // 求最大公约数，辗转相除法
                int gcd = gcd(x, y);
                // 对 x 和 y 同时约分
                x /= gcd;
                y /= gcd;
                // 这里加上 "$" 可以转化成字符串存入 map 的键元素中
                String key = x + "$" + y;
                map.put(key, map.getOrDefault(key, 0) + 1);
                max = Math.max(max, map.get(key) );
            }
        // 结果包括：一条线上最多的点（不包含重复的和自己本身）+重复的点+自己本身
            ans = Math.max(ans, max + duplicate + 1);
        }
        return ans;
    }
    
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }   
        return a;
    }
}
```