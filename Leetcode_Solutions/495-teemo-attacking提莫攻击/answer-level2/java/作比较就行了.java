![image.png](https://pic.leetcode-cn.com/1ac946e956ef7f0ff4e8e5c9774803d56668142748856c22528c6444cc40968a-image.png)

```
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int answer, i;

        if(timeSeries.length == 0)
            return 0;
        answer = 0;
        for(i = 0; i < timeSeries.length - 1; i++){
            if(timeSeries[i+1] - timeSeries[i] < duration)
                answer += timeSeries[i+1] - timeSeries[i];
            else
                answer += duration;
        }
        answer += duration;
        return answer;
    }   
}
```
