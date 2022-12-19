### 解题思路
请看代码

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0){
            return 0;
        }
        int head = 0;
        int length = nums.length;
        int tail = length-1;
        while(head<tail){
            // 相邻了
            if(head == tail - 1){
                break;
            }
            int pos = (head+tail) / 2;
            if(target > nums[pos]){
                head = pos;
                continue;
            }
            if(target < nums[pos]){
                tail = pos;
                continue;
            }
            if(target == nums[pos]){
                return pos;
            }
        }
        if(target<=nums[head]){
            return head;
        }
        if(target>nums[head] && target <nums[tail]){
            return head+1;
        }
        if(target == nums[tail]){
            return tail;
        }
        if(target >nums[tail]){
            return tail+1;
        }
        return 0;
    }
}
```