```
public int mincostTickets(int[] days, int[] costs) {
        if(null == days || 0 == days.length || null == costs || 0 == costs.length){
            return 0;
        }
        int[] dp = new int[days.length];
        dp[0] = Math.min(Math.min(costs[0],costs[1]),costs[2]);
        int index = 1;
        while(index<days.length){
            int curCost = dp[index-1] + costs[0];
            int j = index -1; 
            while(j>=0 && days[index]-days[j]<7){
                j--;
            }
            if(j<0){
                curCost = Math.min(curCost, costs[1]);
            }else {
                curCost = Math.min(curCost, costs[1]+dp[j]);
            }
            int k = index-1;
            while(k>=0 && days[index]-days[k]<30){
                k--;
            }
            if(k<0){
                curCost = Math.min(curCost, costs[2]);
            }else {
                curCost = Math.min(curCost, costs[2]+dp[k]);
            }
            dp[index] = curCost;
            index++;
        }
        return dp[days.length-1];
    }
