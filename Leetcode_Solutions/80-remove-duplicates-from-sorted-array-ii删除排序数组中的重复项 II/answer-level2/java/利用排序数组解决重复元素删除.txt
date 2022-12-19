### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 0;
        for(int n:nums)
            //利用排序数组，若n>nums[index-2],说明该数据是新数据，可以直接存入数组头部；
            //同理，可解决重复数组元素个数不超过任意数的问题(在排序数组下)
            if(index<2||n>nums[index-2]) 
                nums[index++] = n;
        return index;
    }
}
```