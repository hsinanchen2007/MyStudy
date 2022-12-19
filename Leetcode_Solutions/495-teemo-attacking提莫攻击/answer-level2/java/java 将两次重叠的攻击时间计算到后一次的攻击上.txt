每一次攻击的持续时间可能不会被后一次攻击，则持续时间为 duration;
每一次攻击的持续时间也可能会被后一次攻击，则将重叠的时间计算到后一次的攻击上，持续时间为 两次攻击间隔;
```java []
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        if(timeSeries == null || timeSeries.length == 0) return 0;

        int count = 0;
        for (int i = 1; i < timeSeries.length; i++) {
            count += Math.min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return count + duration;
    }
}
```
