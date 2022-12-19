# 思路
 从nums[0]开始，放到该数的新位置(0 + k)，然后再寻找该位置值的新位置，直至回到0时结束。
 但是该方法不能保证遍历完所有的位置，如 7 位的数组后移3个位置只需遍历一遍，而 6 位的数组后移4个位置需要遍历两遍（再从i = 1开始）。
 可以发现这个遍历的次数就是数组长度和k的最大公约数。
# 代码
```java
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        for (int i = 0;i < gcd(k, len);i++){
            int idx = (k + i) % len, num = nums[i];
            while (idx != i){
                int item = nums[idx];
                nums[idx] = num;
                idx = (idx + k) % len;
                num = item;
            }
            nums[i] = num;
        }
    }

    private int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b % a, a);
    }
```