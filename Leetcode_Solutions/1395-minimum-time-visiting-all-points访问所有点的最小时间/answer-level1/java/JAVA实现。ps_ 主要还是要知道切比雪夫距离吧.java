
```
    public int minTimeToVisitAllPoints(int[][] points) {

        int sum = 0;
        int[] pre = null;
        for (int[] point : points) {
            if (pre == null) {
                pre = point;
                continue;
            }
            int x = point[0] - pre[0];
            int y = point[1] - pre[1];
            sum += Math.max(Math.abs(x), Math.abs(y));
            pre = point;
        }
        return sum;
    }
```
[切比雪夫距离](https://baike.baidu.com/item/%E5%88%87%E6%AF%94%E9%9B%AA%E5%A4%AB%E8%B7%9D%E7%A6%BB)。