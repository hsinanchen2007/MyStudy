### 要计算第i号员工最早什么时候能够被通知，只要知道他的上司boss最早被通知的时间t,那么ii被通知的时间就是t+infoTime[boss]。用一个数据记忆每个员工的最早通知时间，这样帝国的时候可以避免重复计算。
```
class Solution {
    int[]earliestTime;
    int[]manager;
    int[]informTime;
    int getEarliestTime(int id){
        if(manager[id] == -1){
            return 0;
        }
        else{
            int boss = manager[id];
            if(earliestTime[id] != 0){
                return earliestTime[id];
            }
            else{
                earliestTime[id] = getEarliestTime(boss) + informTime[boss];
                return earliestTime[id];
            }
        }
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        earliestTime = new int[manager.length];
        this.manager = manager;
        this.informTime = informTime;
        int ret = 0;
        for(int i = 0;i < manager.length;++i){
            ret = Math.max(ret,getEarliestTime(i));
        }
        return ret;
    }
}
```

时间和空间复杂度都是O(n)