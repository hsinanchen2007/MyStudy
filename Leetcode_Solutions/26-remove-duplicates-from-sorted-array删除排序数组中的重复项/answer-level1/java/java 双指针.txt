### 解题思路
双指针

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;
        for(int j= 0; j<nums.length ; j++){
            if(nums[i]==nums[j]){
                continue;
            }else{
                i++;
                nums[i]=nums[j];
            } 
        }
        return i+1;
    }
}
```