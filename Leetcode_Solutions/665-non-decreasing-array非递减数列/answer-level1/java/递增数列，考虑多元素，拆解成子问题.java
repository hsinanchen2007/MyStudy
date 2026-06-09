### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int count = 0;
        for(int i=0; i< nums.length-1; i++) {
            int temp = nums[i];
            if(nums[i] > nums[i+1]) {
                if(i > 0) {
                    nums[i] = nums[i-1];
                } else {
                    nums[i] = nums[i+1];
                }
                if(nums[i] > nums[i+1]) {
                    nums[i+1] = temp;
                }
                count++;
                if(count == 2) {
                    return false;
                }
            }
        }
        return true;
    }
}
```