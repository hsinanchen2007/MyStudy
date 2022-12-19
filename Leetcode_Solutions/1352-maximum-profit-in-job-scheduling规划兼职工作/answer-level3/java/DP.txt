动态规划  
复杂度还是平方
开始超时
改进，
如果两个数i, j
dp[i] < dp[j]
且ranges[j].end时间上满足早于开始时间，那么i就不用每次遍历了 

```
class Solution {
    /*********************************************
    1. DP 
       O(n * n)
    2. Improve performance
       store the position from which DP comparing should start
    
    ***************************************************/
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        Range[] ranges = new Range[n];
        for (int i = 0; i < n; i++) {
            ranges[i] = new Range(startTime[i], endTime[i], profit[i]);
        }
        Arrays.sort(ranges, (r1, r2) -> r1.start -r2.start);
        int[] dp = new int[n];
        Integer[] ends = new Integer[n];
        for (int i = 0; i < n ; i++) {
            ends[i] = i;
        }
        Arrays.sort(ends, (i, j)->ranges[i].end-ranges[j].end);
        int pos = 0;
        for (int i = 0; i < n; i++) {
            Range range = ranges[i];
            if (i == 0) {
                dp[0] = range.profit;
            }
            else {
                int res = 0;
                for (int j = pos; j < n; j++) {
                    int idx= ends[j];
                    if (ranges[idx].end <= range.start) {
                        res = Math.max(res, dp[idx]);
                        if (dp[idx] > dp[ends[pos]]) {
                            pos = j;
                        }
                    }
                    else {
                        break;
                    }
                }
                dp[i] = res + range.profit;
            }
        }
        
        return Arrays.stream(dp).max().getAsInt();
    }
    
    class Range{
        int start;
        int end;
        int profit;
        
        public Range(int s, int e, int p) {
            start = s;
            end = e;
            profit = p;
        }
    }
}
```
执行用时 :103 ms
内存消耗 :51.5 MB

