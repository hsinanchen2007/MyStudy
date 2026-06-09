### 解题思路
同删除排序数组中的重复项，受此题启发，写的这个代码，其实也是双指针的思想。

要求移除所有数值等于val的元素，实际上就是将不重复的元素移到数组的左侧。

考虑用两个指针，一个在前记作i，一个记作j，思想如下：

比较j位置的元素是否与val相等，如果相等，j后移一位，如果不相等，将j位置的元素复制到i位置上，然后i后移一位，j后移一位。
重复上述过程，直到j等于数组长度，
返回i，即为新数组的长度。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i=0;
        int j=0;
        while(j<nums.length){
            if(nums[j]==val){
                j++;
            }else{
                nums[i++]=nums[j++];
            }
        }
        return i;
    }
}
```