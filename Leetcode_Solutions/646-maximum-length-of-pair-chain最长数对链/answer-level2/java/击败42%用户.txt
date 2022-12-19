### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    class myComparator implements Comparator<int[]>{
        @Override
        public int compare(int[] a, int[] b){
            return a[0] - b[0];
        }
    }
    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        if(n == 0){
            return 0;
        }
        // 将pairs先排序
        Arrays.sort(pairs, new myComparator());
        // dp记录以n为结束的最大的数对数
        int[] dp = new int[n];
        dp[0] = 1;
        int index = 1;
        while(index < n){
            // 就算一个都连不了，自身算一个
            dp[index] = 1;
            for(int i = 0; i < index; i++){
                // 可以连在后面
                if(pairs[index][0] > pairs[i][1]){
                    dp[index] = Math.max(dp[index], dp[i] + 1);
                }
            }
            index++;
        }
        // 找出dp中的最大值
        int longest = 0;
        for(int i = 0; i < n; i++){
            longest = dp[i] > longest ? dp[i] : longest;
        }
        return longest;
    }
}
```