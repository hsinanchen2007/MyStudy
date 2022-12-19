1. sumLeft + sumRight + nums[p] = sumTotal;
2. sumLeft = sumRight
3. 可以得出 sumLeft * 2 + nums[p] = sumTotal;

```
        int sumTotal = 0;
        int sumLeft = 0;
        for (int i = 0; i < nums.length; i++) {
            sumTotal += nums[i];
        }
        for (int p = 0; p < nums.length; p++) {

            if (sumLeft * 2 == sumTotal - nums[p]) {
                return p;
            }
            sumLeft += nums[p];
        }
        return -1;
```
