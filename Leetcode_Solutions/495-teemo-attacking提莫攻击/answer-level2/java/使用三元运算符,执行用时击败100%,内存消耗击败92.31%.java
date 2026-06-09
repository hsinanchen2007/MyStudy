### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
       int result = 0;
       if(timeSeries.length == 0){
           return 0;
       }
        for (int i = 1; i < timeSeries.length; i++) {
            result+= (timeSeries[i]-timeSeries[i-1]>duration?duration:timeSeries[i]-timeSeries[i-1]);
        }
        return result+duration;
    }
}
```