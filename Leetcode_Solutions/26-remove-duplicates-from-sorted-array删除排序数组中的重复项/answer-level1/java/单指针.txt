### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int len = 1;
        for(int i = 1;i<nums.length;i++){
            if(nums[i]!=nums[i-1]){
                nums[len] = nums[i];
                len++;
            }
            
        }
        return len;
    }
}
```