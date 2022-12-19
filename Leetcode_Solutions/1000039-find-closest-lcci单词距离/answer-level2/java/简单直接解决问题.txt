### 解题思路
不用想得太复杂，就是计算2个点之间的距离，dp[0]=最新出现的单词1的位置，dp[2]=最新出现的单词2的位置，和历史数据做一下比对，小的话min替换成当前值，如果min==1了，不用往下走了，直接返回即可，已经是最小值了。

### 代码

```java
class Solution {
    public int findClosest(String[] words, String w1, String w2) {
        if(Objects.isNull(words)||words.length==0){
            return 0;
        }
        //存储点位置 0固定存word1最新出现的位置，1固定存word2最新出现的位置
        int[] dp = new int[2];
        dp[0] = -1;
        dp[1] = -1;
        int min = Integer.MAX_VALUE; 

        for(int i=0;i<words.length;i++){
            String curr = words[i];
            if(curr.equals(w1)){
                dp[0] = i;
                if(dp[1]>=0){
                    min = Math.min(min,Math.abs(dp[1]-dp[0]));
                }
            }else if(curr.equals(w2)){
                dp[1] = i;
                if(dp[0]>=0){
                    min = Math.min(min,Math.abs(dp[1]-dp[0]));
                }
            }
            if(min == 1){
                return min;
            }
        }
        return min;
        
    }
}
```