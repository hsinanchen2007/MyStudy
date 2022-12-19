``` java
public int findLengthOfLCIS(int[] nums) {
        int tmp = nums.length > 0 ? 1 : 0;
        int a = nums.length > 0 ? 1 : 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i]) {
                a++;
            } else {
                if (a > tmp) {
                    tmp = a;
                }
                a = 1;
            }
        }
        return tmp > a ? tmp : a;
}
```
