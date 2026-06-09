### 解题思路
有问题的可以留言

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        int count = len,index = 1;
        for(int i=0;i<len-1;i++){
            if(nums[i]==nums[i+1]){
                count--;
            }else {
                nums[index] = nums[i+1];
                index++;
            }
        }
        
        return count;
    }
}
```