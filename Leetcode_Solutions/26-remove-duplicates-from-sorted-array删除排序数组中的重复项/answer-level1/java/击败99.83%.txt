### 解题思路

想法很简单，len指针用来记录没重复数字的位置。
这里要注意的是第一个if判断条件只能存前一个数，如[0,1]，这里只能存上0，1就存不上，所以要加上第二个if条件，无论原数组是什么样的，原数组醉胡一个数一定算一个未重复的数

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int len=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[len]=nums[i];
                len++;
            }
            if(i==nums.length-2)  //注意这个条件
                nums[len]=nums[i+1];  
        }
        return len+1;
    }
}
```