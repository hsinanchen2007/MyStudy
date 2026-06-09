### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        if(n < 2){
            return n;
        }
        // 捕捉下降沿
        int low = 1;
        // 捕捉上升沿
        int high = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > 0){
                high = low + 1;
            }
            else if(nums[i] - nums[i-1] < 0){
                low = high + 1; 
            }
        }
        return Math.max(high, low);
    }
}
```