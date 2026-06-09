### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        
        int n = nums.length;
        int cnt = 1;
        int i = 0;
        for(int j = 1; j < n; j++) {
            if(nums[j] == nums[j - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            
            if(cnt <= 2) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
}
```