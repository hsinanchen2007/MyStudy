转换为分钟，排序后相邻的计算，最后计算首尾两个数值的计算。

```
private int parse(String str) {
        String[] times = str.split(":");
        String hour = times[0];
        String minute = times[1];
        
        int t = (minute.charAt(0) - '0') * 10 + (minute.charAt(1) - '0');
        t += (60 * ((hour.charAt(0) - '0') * 10 + (hour.charAt(1) - '0')));
        return t;    
    }
    
    public int findMinDifference(List<String> timePoints) {
        int len = timePoints.size();
        if (len < 2) {
            return 0;
        }
        int[] times = new int[len];
        for(int i = 0; i < len; i++) {
            times[i] = parse(timePoints.get(i));
        }
        
        Arrays.sort(times);
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < len - 1; i++) {
            min = Math.min(min, times[i+1] - times[i]);
        }
        
        min = Math.min(min, 24 * 60 - times[len - 1] + times[0]);
        
        return min;
    }
```