### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0)
            return 0;
        int j=0;
        int i;
        for(i=1;i<nums.length;i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
        
    }
}
```