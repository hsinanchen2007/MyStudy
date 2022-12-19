讲道理，这题真的简单
只需要判定一下出发站和到达站，一次遍历即可

```
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < distance.length; i++) {
            if ((i >= start && i < destination) || (i >= destination && i < start)) {
                sum1 += distance[i];
            } else {
                sum2 += distance[i];
            }
        }
        return Math.min(sum1, sum2);
    }
```
