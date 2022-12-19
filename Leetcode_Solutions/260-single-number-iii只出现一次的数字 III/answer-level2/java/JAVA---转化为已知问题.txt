已知： 数组中只有一个数字出现一次，其他都出现两次的问题解法

全部异或，则结果为两个出现一次的元素的异或；
找到异或结果的一个1，然后根据这一位是0 还是 1将所有数字分成两组， 转化为已知问题

```
    public int[] singleNumber(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return nums;
        }
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        // 找到1的位置
        int oneIndex = 0;
        while (oneIndex < 32) {
            if ((xor >> oneIndex & 1) == 1) {
                break;
            }
            oneIndex++;
        }
        // 分成两组，分别计算结果
        int[] res = new int[2];
        for (int num : nums) {
            if ((num >> oneIndex & 1) == 0) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
```