### 解题思路
将时间转换为分钟单位，即01:00 转换为数字60，然后将整个列表进行排序， 这样就可以很方便的计算出，相邻时间段的分钟间隔的最小值

但是需要注意的是题例里面跨天的情况，这种情况下，将排序的最开始一个时间点加上一天的分钟数1440，再减去最后一个时间点的分钟数，就是这两个跨天时间点的间隔。

### 代码

```java
class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> timeList = new ArrayList<>(timePoints.size());
        for (String timePoint : timePoints) {
            timeList.add(getTime(timePoint));
        }
        Collections.sort(timeList);
        int min = 1440;
        for (int i=0;i<timeList.size()-1;i++) {
            min = Math.min(min, timeList.get(i+1) - timeList.get(i) );
        }
        min = Math.min(min, timeList.get(0)+1440 - timeList.get(timeList.size()-1));
        return min;
    }

    private int getTime(String timePoint) {
        String[] time = timePoint.split(":");
        return Integer.valueOf(time[0])*60 + Integer.valueOf(time[1]);
    }

}
```