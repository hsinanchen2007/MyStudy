```
public int numTimesAllBlue(int[] light) {
        int max = 0;
        int n = light.length;
        int res = 0;
        for(int i = 0; i < n; i++) {
            max = Math.max(max, light[i]);
            if (max == i + 1) {
                res++;
            }
        }
        return res;
    }
```
