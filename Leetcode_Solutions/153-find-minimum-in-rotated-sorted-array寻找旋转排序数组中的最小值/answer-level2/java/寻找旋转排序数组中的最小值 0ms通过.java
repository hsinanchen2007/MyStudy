### 解题思路
找到不是递增的索引，就是那个数了

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        for(int i=1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
}
```