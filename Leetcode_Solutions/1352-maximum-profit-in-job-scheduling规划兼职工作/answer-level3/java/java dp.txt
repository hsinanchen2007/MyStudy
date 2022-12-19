### 解题思路
按照endtime排序 动态规划

### 代码

```java
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        List<List<Integer>> data = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            List<Integer> temp = new ArrayList<Integer>();
            temp.add(startTime[i]);
            temp.add(endTime[i]);
            temp.add(profit[i]);
            data.add(temp);
        }
        Collections.sort(data, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> left, List<Integer> right) {
                return left.get(1) - right.get(1);
            }
        });
        int[] dp = new int[n];
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                dp[i] = data.get(i).get(2);
                continue;
            }
            int pre = i - 1;
            while (data.get(i).get(0) < data.get(pre).get(1)) {
                --pre;
                if (pre < 0) {
                    break;
                }
            }
            if (pre >= 0) {
                dp[i] = Math.max(dp[pre] + data.get(i).get(2), dp[i - 1]);
            } else {
                dp[i] = Math.max(data.get(i).get(2), dp[i - 1]);
            }
            result = Math.max(result, dp[i]);
        }
        return result;
    }
}
```