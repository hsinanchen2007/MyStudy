![image.png](https://pic.leetcode-cn.com/a59e60ca0508ca76444f23083442dd8e1e7490b7fe742812f529ad41c71cc3e9-image.png)

```
    public int maxDistToClosest(int[] seats) {
        int max = 0;
        int cnt = 0;
        int i = 0;
        while(i < seats.length) {
            while(i < seats.length && seats[i] == 0) {
                i++;
                cnt++;
            }
            if(max < (cnt + 1)/ 2) {
                max = (cnt + 1)/ 2;
            }
            cnt = 0;
            i++;
        }
        cnt = 0;
        i = 0;
        if(seats[0] == 0) {
            while(seats[i] == 0) {
                i++;
                cnt++;
            }
            if(max < cnt) {
                max = cnt;
            }
        }
        i = seats.length - 1;
        cnt = 0;
        if(seats[seats.length - 1] == 0) {
            while(seats[i] == 0) {
                i--;
                cnt++;
            }
            if(max < cnt) {
                max = cnt;
            }
        }
        return max;
    }
```

