```
public static int findPoisonedDuration(int[] timeSeries, int duration) {
        if (timeSeries.length == 0) return 0;
        if (timeSeries.length <= 1) return duration;
        int sumdura = 0;
        for (int i = 1; i < timeSeries.length; i++) {
            if ((timeSeries[i] - timeSeries[i-1]) > duration){
                sumdura += duration;
            }else{
                sumdura += timeSeries[i] - timeSeries[i-1];
            }
        }
        sumdura+=duration;
        return sumdura;
    }
```
