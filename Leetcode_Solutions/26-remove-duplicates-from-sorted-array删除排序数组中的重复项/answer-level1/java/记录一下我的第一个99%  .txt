### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }else{
            int i = 0;
            int temp = nums[0];
            for(int j = 1;j < nums.length;j++){
                if(temp==nums[j]){
                    continue;
                }else{
                    nums[i] = temp;
                    i++;
                    temp = nums[j];
                }
            }
            if(temp!=nums[i]){
                nums[i] = temp;
            }
            return i+1;
        }
    }
}
```