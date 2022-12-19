### 解题思路
当我们发现一个递减的数字的时候，y > z， 我们还需要分析一下y前一位数字x的情况。
当 x < y, x < z的时候，设置y = z；
当 x < y, x = z的时候，设置z = y;
当 x < y, x > z的时候，设置z = y；
当 x = y, x > z的时候，设置z = y。

我们可以更改一次，当更改的次数超过1次，则返回错误。

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 1; i++){
            if (nums[i + 1] < nums[i]){
                if (i == 0 || (nums[i - 1] < nums[i] && nums[i - 1] < nums[i + 1])){
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
                count ++;
            }
            if (count > 1){
                return false;
            }
        }

        return true;
    }
}
```