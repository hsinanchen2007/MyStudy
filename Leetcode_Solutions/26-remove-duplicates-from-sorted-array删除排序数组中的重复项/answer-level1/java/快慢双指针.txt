### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0)
            return 0;
        int p = 0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] != nums[p]){
                if(i-p>1){
                    nums[p+1] = nums[i];
                }
                p++;
            }
        }
        return p+1;
    }
}
```