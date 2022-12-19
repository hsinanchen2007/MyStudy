### 解题思路
此题的做法为双指针，左指针往前搜索，右指针进行优化最小。
开始的时候需要注意min值的选取。第一次赋值需要判断是否为0，之后的才需要取较小的值。

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int right, left;
        int sum = 0;
        int min = 0;

        for(right = 0, left = 0; right < nums.length && left <= right;){
            sum = sum + nums[right];
            if(sum < s)
                right++;
            else{
                if(min == 0)
                    min = right - left + 1;
                else
                    min = Math.min(min, right - left + 1);
                sum = sum - nums[left];
                //注意下面这一行代码需要加上，因为前面一直有在加。
                sum = sum - nums[right];
                left++;
            }
        }
        return min;
    }
}
```