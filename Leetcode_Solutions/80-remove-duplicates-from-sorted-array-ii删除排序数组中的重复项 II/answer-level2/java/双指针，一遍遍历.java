```java
class Solution {
    public int removeDuplicates(int[] nums) {
        // 标记用来替换的位置
        int index = 0;
        // 标记相同的数字个数
        int count = 0;

        // 一遍遍历
        for(int i = 0; i< nums.length; i++){
            if(i == 0 || nums[i] == nums[i-1]){
                count++;
            }else if(nums[i] != nums[i-1]){
                count = 1;
            }
            
            // 小于二，标记指针移动
            if(count <= 2){
                nums[index++] = nums[i];
            }
        }
        
        return index;
    }
}
```