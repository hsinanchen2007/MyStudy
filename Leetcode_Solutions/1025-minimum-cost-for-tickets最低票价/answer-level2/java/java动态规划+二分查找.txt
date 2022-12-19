设置动态规划数组dp，dp[i]代表**第i天可能的最低支出**。对于days数组的某一天，分别找到向前1天、向前7天、向前30天的最低支出，然后加上1天、7天、30天票价，取三者最小的作为dp[i]的值，即第i天可能的最低支出。
为了加快向前查找第(i - 1/7/30)天最低支出的速度，选择二分查找。
```
class Solution{
    public int mincostTickets(int[] days, int[] costs) {
        if(days == null || days.length == 0)
            return 0;
        int len = days.length;
        int[] dp = new int[len];
        for (int i = 0; i < len; i++) {
            int buy1Pass = getMinCost(days, costs, dp, 1, i);
            int buy7Pass = getMinCost(days, costs, dp, 7, i);
            int buy30Pass = getMinCost(days, costs, dp, 30, i);
            dp[i] = Math.min(buy1Pass, Math.min(buy7Pass, buy30Pass));
        }
        return dp[len - 1];
    }
    private int getMinCost(int[] days, int[] costs, int[] dp, int passType, int index){
        int day = days[index];
        int passCost;
        switch (passType) {
            case 1: passCost = costs[0];break;
            case 7: passCost = costs[1];break;
            default: passCost = costs[2];
        }
        int preCost = binSearchCost(days, dp, day - passType, 0, index - 1);
        return preCost + passCost;
    }
    private int binSearchCost(int[] days, int[] dp, int day, int left, int right){
        if(left >= right){
            if(days[left] > day)
                return left - 1 >= 0 ? dp[left - 1]: 0;
            else return dp[left];
        }
        int mid = (left + right) / 2;
        if(days[mid] > day){
            return binSearchCost(days, dp, day, left, mid - 1);
        } else if(days[mid] < day){
            return binSearchCost(days, dp, day, mid + 1, right);
        } else return dp[mid];
    }
}
```
