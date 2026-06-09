### 解题思路
**分析**
对于这个数组，进行排序后
一定有在nums.length/2的长度内出现重复
顾只要循环排序后的数组，在从i开始比较nums.length/2+i处是否相同。
时间复杂度为O(nlogn));

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
       Arrays.sort(nums);
      for(int i=0;i<nums.length;i++){
          if(nums[i] == nums[nums.length/2+i]){
              return nums[i];
          }
      }
       return 0;
    }
}
```