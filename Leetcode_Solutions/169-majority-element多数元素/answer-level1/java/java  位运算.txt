思路：由于众数数组中出现次数大于n/2 ，那么众数对应的二进制每一个为1的位数出现的次数一定大于n/2，由此可以得出众数
```
public int majorityElement(int[] nums) {
        int result = 0, k = nums.length >> 1;
        for (int j = 0; j < 32; j++) {
            int count = 0;
            for (int num : nums) {
                count += num >> j & 1;
                if (count > k) {
                    result += 1 << j;
                    break;
                }
            }
        }
        return result;
    }
```
复杂度分析

时间复杂度：O(n)

空间复杂度：O(1)



