### 解题思路
重新排序后，只看当前的和前一个数值差只有1的数组，并计算两个数值总共的长度。

### 代码

```java
class Solution {
    public int findLHS(int[] nums) {
        if (nums.length == 1){
            return 0;
        }
        Arrays.sort(nums);

        // 重新排序后，只看当前的和前一个数值差只有1的数组，并计算两个数值总共的长度。
        int maxLength = 0;
        for (int i = 1; i < nums.length; i++){
            if (nums[i] != nums[i-1] && nums[i] - nums[i-1] == 1){
                int previous = i-1;
                while (previous - 1 >= 0 && nums[previous] == nums[previous - 1]){
                    previous--;
                }
                int current = i;
                while(current + 1 < nums.length && nums[current+1] == nums[current]){
                    current++;
                }
                if (current - previous + 1> maxLength){
                    maxLength = current - previous + 1;
                }
            }
        }

        return maxLength;
    }
}
```