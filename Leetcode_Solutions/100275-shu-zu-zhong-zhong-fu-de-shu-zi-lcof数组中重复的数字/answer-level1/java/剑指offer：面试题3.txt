### 解题思路
若不存在重复元素，排序后，数组下标一定等于该元素本身。
扫描一遍数组，若该下标与该下标索引的值不相等，将该值与下标等于该值的元素比较，若相等m，则重复，不相等则交换
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
             int temp;
          for(int i=0;i<nums.length;i++){
            while(i!=nums[i]){
              if(nums[i]==nums[nums[i]]){return nums[i];}
              else { temp=nums[i];
              nums[i]=nums[temp];
              nums[temp]=temp;}
          }}
           return -1;
    }
   
}

    

```