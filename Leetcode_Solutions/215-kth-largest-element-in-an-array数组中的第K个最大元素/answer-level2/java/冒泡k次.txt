### 解题思路


### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {//冒泡k次
         for(int i=0;i<k;i++)
          for(int j=0;j<nums.length-i-1;j++)
          {
              if(nums[j]>nums[j+1])
               swap(nums,j,j+1);
          }
          return nums[nums.length-k];
    }
    private void swap(int[] nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
```