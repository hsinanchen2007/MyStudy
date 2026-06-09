增加两个数组指针，一个保存最大值索引，一个保存第二大值索引，做好边界的计算，代码应该可以更加简化。
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
      int i, max, maxidx = 0, seconedmax, sencondmaxidx = 1;
        if (k == 0) {
            return new int[0];
        }
        if (k == 1) {
            return nums;
        }
        //init
        int res[] = new int[nums.length - k + 1];
        max = nums[0];
        seconedmax = nums[1];
        for (i = 1; i < k; i++) {
            if (nums[i] >= max) {
                seconedmax = max;
                sencondmaxidx = maxidx;
                max = nums[i];
                maxidx = i;
            } else if (nums[i] >= seconedmax) {
                seconedmax = nums[i];
                sencondmaxidx = i;
            }
        }
        res[0] = max;
        int m;
        for (i = k, m = 1; i < nums.length; i++, m++) {
            if (i - maxidx < k) {
                if (nums[i] >= max) {
                    seconedmax = max;
                    sencondmaxidx = maxidx;
                    max = nums[i];
                    maxidx = i;
                } else if (nums[i] >= seconedmax) {
                    seconedmax = nums[i];
                    sencondmaxidx = i;
                }
                res[m] = max;
            } else {
                if (nums[i] >= seconedmax) {
                    max = nums[i];
                    maxidx = i;
                    res[m] = max;
                } else {
                    max = nums[i - k + 1];
                    seconedmax = nums[i - k + 2];
                    for (int j = i - k + 2; j <= i; j++) {
                        if (nums[j] >= max) {
                            seconedmax = max;
                            sencondmaxidx = maxidx;
                            max = nums[j];
                            maxidx = j;
                        } else if (nums[j] >= seconedmax) {
                            seconedmax = nums[j];
                            sencondmaxidx = j;
                        }
                    }
                    res[m] = max;
                }
            }
        }
        return res;
    }
}
```
