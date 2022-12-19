### 解题思路
此处撰写解题思路
计算每个加油站，有的汽油和到下个加油站所需汽油的差值。想要跑完全程，那么，每时每刻的差值必须大于等于0，所以我们要找到一个加油站的序列，使得每次差值的和都大于等于0即可。
### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] diff = new int[n];
        int sum = 0;
        for(int i=0;i<n;i++){
            diff[i] = gas[i]-cost[i];
            sum = sum + diff[i];
        }
        if(sum<0) return -1;
        int begin = 0;
        sum = 0;
        for(int i = 0;i<n;i++){
            sum += diff[i];
            if(begin==0&&i==n-1&&sum>=0) return 0;
            if(begin<n&&i==begin-1&&sum>=0) return begin;
            if(begin>=n){
                break;
            }
            if(sum < 0){
                begin = i+1;
                sum = 0;
            }
            if(i==n-1){
                i = -1;
            }
            
        }
        return -1;
        
    }
}
```