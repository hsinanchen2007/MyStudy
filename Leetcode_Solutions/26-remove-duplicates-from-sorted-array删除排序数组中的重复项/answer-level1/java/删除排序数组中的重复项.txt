### 解题思路
此处使用两个指针一个指针用来遍历整个数组，一个数组用来将不重复的数组存储起来，最后两者之间间隔个数就是重复的数

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==1){
            return 1;
        }
        int n = 0;
        int i = 0;
        int j = 0;
        while(j<nums.length){
            if(nums[i]==nums[j]){
                j++;
            }else{
                nums[++i] = nums[j];
            }
        }
        return nums.length-j+i+1;
    }
}
```