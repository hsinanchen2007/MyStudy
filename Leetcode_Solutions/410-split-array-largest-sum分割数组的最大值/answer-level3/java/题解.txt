```Java
    public int splitArray(int[] nums, int m) {
        //划分之后子数组最大值，大于数组中最大的一个元素，小于数组的总和
        long l = 0;
        long r = 0;
        int n = nums.length;
        //r是数组总和，l是数组中最大的值
        for (int i = 0; i < n; i++) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }
        long ans = r;
        while (l <= r) {
            //求出中间值mid，计算子数组和不大于mid时，能划分出几个子数组
            long mid = (l + r) >> 1;
            long sum = 0;
            int cnt = 1;//划分的子数组个数,初始值为1是因为，下面只在分割处加了1，分割1次，数组长度为2，所以初始值为1
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m) {//划分出来的子数组少于m个，说明mid值大了
                ans = Math.min(ans, mid);
                r = mid - 1;
            } else {//划分出来的子数组多于m个，说明mid值小了
                l = mid + 1;
            }
        }
        return (int) ans;
    }
```
