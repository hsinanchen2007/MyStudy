## 分析
因为本题数据样本仅为3种数字。所以我们可以建一个空间为3的数组，表示每种数字出现的次数。
   最后从小到大。将每种数字赋值的原数组中。
##    代码
```java
public void sortColors(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int[] tmp = new int[3];
        for (int num : nums) {
            tmp[num]++;
        }
        for (int i = 0; i < nums.length; i++) {
            if (tmp[0]-- > 0) {
                nums[i] = 0;
            } else {
                if (tmp[1]-- > 0) {
                    nums[i] = 1;
                } else {
                    nums[i] = 2;
                }
            }

        }
    }
```