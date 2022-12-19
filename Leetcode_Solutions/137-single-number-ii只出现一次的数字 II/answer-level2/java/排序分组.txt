### 解题思路
1. 排序
2. 三个一组，找出不同的那一个

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i += 3) {
            if (nums[i] != nums[i + 2]) {
                return nums[i + 1] == nums[i] ? nums[i + 2] : nums[i];
            }
        }
        return nums[nums.length - 1];
    }
}
```
方法二：效率更高，但是没看懂

public int singleNumber(int[] nums) {
        int ones = 0, twos = 0;
        for(int num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
