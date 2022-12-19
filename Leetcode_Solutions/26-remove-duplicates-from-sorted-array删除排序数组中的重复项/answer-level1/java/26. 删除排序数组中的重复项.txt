### 解题思路
题目给定为排序数组，数组中元素有序，以i为标准，判断nums[j]与nums[i]是否不同，如不同则将nums[j]放入nums[i+1]中，最后返回i+1即为新数组长度，即数组中不重复元素个数。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;
        for(int j=i+1;j<nums.length;j++){
            if(nums[i]!=nums[j]){
                nums[++i]=nums[j];
            }
        }      
        return i+1;
    }
}
```