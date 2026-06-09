### 解题思路
将nums[nums[i]]置为-1，如果下次再遍历发现该地方为-1，则说明遍历成功

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != -1 && nums[nums[i]] == -1) {
                return nums[i];
            } else if(nums[i] != -1){
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = -1;
                i --;
            }
        }
        return 0;
    }
}
```