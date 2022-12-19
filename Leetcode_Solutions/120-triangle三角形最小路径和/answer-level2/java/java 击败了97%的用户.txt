```
public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle == null || triangle.size() == 0){
            return 0;
        }
        int len = triangle.size();
        //为什么用len+1，其实相当于最后一层全为0
        /**
         * [
         *  *      [2],
         *  *     [3,4],
         *  *    [6,5,7],
         *  *   [4,1,8,3],
         *  *  [0,0,0,0,0]
         *  * ]
         */
        int[] dp = new int[len+1];

        for (int i = len-1; i >=0 ; i--) {
            //为什么要用first暂存一下dp[i+1]，因为不暂存dp[i+1]的值会被更新掉
            int first = dp[i+1];
            for (int j = i; j >= 0; j--) {
                int second = dp[j];
                dp[j] = Math.min(first,second)+triangle.get(i).get(j);
                first = second;
            }
        }
        return dp[0];
        
    }
```
