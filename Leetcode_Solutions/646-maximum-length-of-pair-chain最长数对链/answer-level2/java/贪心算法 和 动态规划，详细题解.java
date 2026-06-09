### 方法一：贪心算法

```java
class Solution {
    public int findLongestChain(int[][] pairs) {
        // 转换为求：最多的不重叠区间的个数
        // 核心思想：尽可能多的有不重叠的区间，所以取end小的区间,这样后边才有位置放其他的区间(其实也就是有更多的数对)
        // 1.定义排序：按照每个数对的end从小到大排序
        // 2.遍历：pre_end < cur_start 才可以进行数对连接
        Arrays.sort(pairs,(a,b)->a[1]-b[1]);
        int preEnd = Integer.MIN_VALUE;
        int count=0;
        for(int[] curPair : pairs){
            if(preEnd < curPair[0]){
                count++;
            	preEnd = curPair[1];
            }
        }
        return count;
    }
}
```

- 时间复杂度：O(NlogN)
- 空间复杂度：O(N)    排序空间复杂度，与语言有关

### 方法二：动态规划

- 动态规划

- **核心思想：**数对的start进行从小到大排序，在一个长度为 `k`，以 `pairs[j]` 结尾的数对链中，如果 `pairs[j][1] < pairs[i][0]`（数对 `pairs[j]`的 `end`比 数对  `pairs[i]`的`start`小），则以 `pairs[j]` 结尾的数对链之后接上一个`dp[i]`数对，使得数对链长度变为 `k+1`
  - 若 `k+1` > `dp[i]`,说明在`dp[j]`之后接上一个`dp[i]`数对能使得以`dp[i]`结尾的链更长
  - 若  `k+1` <= `dp[i]`,说明在`dp[j]`之后接上一个`dp[i]`数对能使得以`dp[i]`结尾的链更短(或者无变化)
- **状态转移方程：**`dp[i] = max(dp[i], dp[j] + 1)`
- **初始状态：**`dp数组全1`，表示每个数对单独作为链的结尾
- **状态更新：**根据数对的第一个数排序所有的数对，`dp[j]` 存储以 `pairs[j]` 结尾的最长链的长度。当 `j < i` 且 `pairs[j][1] < pairs[i][0]` 时，扩展数对链，更新 
- 时间复杂度：O(N^2)
- 空间复杂度：O(N)

```java
class Solution {
    public int findLongestChain(int[][] pairs) {
        // 1.定义排序：按照每个数对的start从小到大排序
        Arrays.sort(pairs,(a,b)->a[0]-b[0]);
        // dp[i],以第i个数对结尾的链的最大长度
        int[] dp = new int[pairs.length];
        // 2.初始状态
        Arrays.fill(dp,1); 
        for(int i=0;i<pairs.length;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] <  pairs[i][0]){
                    // 3.转移方程
                    // 若dp[j]+1较大 ,则说明在dp[j]之后接上一个dp[i]数对能使得链更长
                    // 若dp[i]较大,这说明在dp[j]之后接上一个dp[i]数对反而使数对更短
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
        }
        // 4.取dp数组中长度最大的
        int max = 0;
        for(int len : dp){
            max = Math.max(len,max);
        }
        return max;
    }
}
```



