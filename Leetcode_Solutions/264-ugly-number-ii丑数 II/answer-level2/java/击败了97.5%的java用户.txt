## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)

```
public int nthUglyNumber(int n) {
        int[] nums = new int[n];

        int index2 = 0;
        int index3 = 0;
        int index5 = 0;

        int tmp = 1;
        nums[0] = 1;

        int value2 = 0;
        int value3 = 0;
        int value5 = 0;
        int cnt = 1;
        while (cnt < n) {
            value2 = nums[index2] * 2;
            value3 = nums[index3]* 3;
            value5 = nums[index5] * 5;
            tmp = Math.min(value2, Math.min(value3, value5));
            nums[cnt++] = tmp;
            if (tmp == value2) {
                index2++;
            }
            if (tmp == value3) {
                index3++;
            }
            if (tmp == value5) {
                index5++;
            }
        }
        return nums[n-1];
        
    }
```
