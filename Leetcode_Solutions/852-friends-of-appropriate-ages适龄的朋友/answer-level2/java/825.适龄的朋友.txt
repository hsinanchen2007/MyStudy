```
class Solution {
    public int numFriendRequests(int[] ages) {
        int[] statistic = new int[121];
        // 统计年龄i的人数
        for (int age: ages){
            statistic[age]++;
        }
        // 统计年龄小于等于i的人数
        for (int i = 1;i<121;i++){
            statistic[i] += statistic[i-1];
        }
        int ans = 0;
        for (int i = 15;i<121;i++){
            int j = i/2+7;
            ans += (statistic[i]-statistic[j]-1) * (statistic[i]-statistic[i-1]);
        }
        return ans;
    }
}
```