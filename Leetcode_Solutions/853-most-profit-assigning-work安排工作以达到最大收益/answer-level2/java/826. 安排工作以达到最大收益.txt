![image.png](https://pic.leetcode-cn.com/bfb71404e4b75908c9b5be48ba7c0dfe1abd95a173a314fe0c3c5bad243d1787-image.png)

```
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int ans, i, j;
        int[][] maxProfits;

        maxProfits = new int[difficulty.length][2];
        for(i = 0; i < difficulty.length; i++){
            maxProfits[i][0] = difficulty[i];
            maxProfits[i][1] = profit[i];
        }
        Arrays.sort(maxProfits, (a, b) -> a[0] - b[0]);
        Arrays.sort(worker);
        //保证难度大的薪水不少于难度低的薪水
        for(i = 1; i < maxProfits.length; i++){
            if(maxProfits[i][1] < maxProfits[i-1][1])
                maxProfits[i][1] = maxProfits[i-1][1];
        }
        ans = 0;
        i = 0;
        j = 0;
        while(j < worker.length){
            while(i < maxProfits.length && maxProfits[i][0] <= worker[j])
                i++;
            if(i > 0)
                ans += maxProfits[i-1][1];
            j++;
        }
        return ans;
    }
}
```
