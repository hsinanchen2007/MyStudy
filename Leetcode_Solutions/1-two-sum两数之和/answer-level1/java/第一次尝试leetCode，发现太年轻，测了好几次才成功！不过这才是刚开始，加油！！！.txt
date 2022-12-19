### 解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = null;
        for(int i = 0;i < nums.length;i++){
            for(int j = 0;j < nums.length;j++){
                if(i ==  j)
                    continue;
                if(nums[i] + nums[j] == target){
                    res = new int[]{i,j};
                }
            }
        }
        return res;
    }
}
```