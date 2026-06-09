### 解题思路
荷兰国旗问题，原理是划边界。
时间复杂度O(n)，空间复杂度O(1)。

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        if(nums == null) return;
        int length = nums.length;
        if(length == 0) return;
        int less = -1;
        int more = length;
        int cur = 0;
        while(cur < more){
            if(nums[cur] == 0){
                nums[cur++] = nums[++less];
                nums[less] = 0;
            }else if(nums[cur] == 2){
                nums[cur] = nums[--more];
                nums[more] = 2;
            }else{
                cur++;
            }
        }
        return;
    }
}
```