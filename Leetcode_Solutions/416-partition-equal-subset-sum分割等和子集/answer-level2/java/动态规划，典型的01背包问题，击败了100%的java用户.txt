典型的01背包问题，关于01背包的详细知识参考[01背包详解](https://blog.csdn.net/reed1991/article/details/53352426)
具体代码如下
```
public boolean canPartition(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum = sum / 2;
        boolean[] res = new boolean[sum + 1];
        res[0] = true;
        for (int num : nums) {
            for (int i = sum; i >= num; i--) {
                res[i] = res[i] || res[i - num];
            }
        }

        return res[sum];
    }
```
