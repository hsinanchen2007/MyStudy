### 解题思路
用快排思想
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int low = 0, high = nums.length - 1;
        while(low < high){
            while(nums[low] % 2 != 0 && low < high)     low++;
            while(nums[high] % 2 == 0 && low < high)     high--;
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
        }
        return nums;
    }
}
```