### 解题思路
普通想法，时间复杂度为O(kn)

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        if(nums.length == 0)
            return -1;
        
        int x = Integer.MIN_VALUE;
        int res = 0;
        int max = x;
        int index = 0;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < nums.length; j++){
                if(nums[j] > max){
                    max = nums[j];
                    index = j;
                }
            }
            res = max;
            max = x;
            nums[index] = x;
        }
        return res;
    }
}
```