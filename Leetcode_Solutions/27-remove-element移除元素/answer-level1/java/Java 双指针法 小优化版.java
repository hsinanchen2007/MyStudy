### 解题思路
指针j代表操作后新数组的尾指针，i代表遍历原数组的的尾指针，但原数组和新数组在同一数组内存中，且i一定大于等于j。当用i遍历的过程中，如果数组成员不是希望删除的val，就把这个成员赋值给j指针指向的数组空格，j++。当然，在遍历的开始还未遍历到val时，j==i的部分，原数组和新数组的部分一致，不需要再改动。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
      
        int j=0;
        for(int i=0;i<nums.length;i++){
           if(nums[i]!=val){
               if(j!=i){
                nums[j]=nums[i];
               }
                  j++;
           }
             }
             return j;

    }
}
```