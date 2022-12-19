### 解题思路
只遍历一次数组所以时间是O(n)， 无需额外空间消耗所以空间是O(1)。假设最佳情况，这n个数字都没有重复，因此数组下标从0~n-1与数组中的数字应该是一一对应的，我们遍历开始比较数组下标与对应位置的值(nums[i])是否相等，假设相等的话就跳到下一个元素，如果不相等就查找下标为nums[i]的元素，看两者是否相等，假设相等就返回该元素，如果不相等，就调换两个位置的数值(目的是将元素nums[i]放到它应该在的位置上)，接着继续判断下标i和调换后新元素nums[i]是否相等，不相等就接着上面步骤。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
           int item;
           for(int i=0;i<nums.length;i++){
               if(nums[i]!=i){
                   if(nums[nums[i]]==nums[i])return nums[i];
               }
               int m=0;
               m=nums[i];
               nums[i]=nums[m];
               nums[m]=m;
           }
           return -1;
    }
}
```