### 解题思路
借鉴快速排序的首尾双指针
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums==null||nums.length==0){
            return nums;
        }
        int temp=nums[0];
        int left=0;
        int right=nums.length-1;
        while(left<right){
            if(nums[right]%2==0) right--;
            nums[left]= nums[right];
            if(nums[left]%2==1) left++;
            nums[right]=nums[left];
        }
        nums[left]=temp;
        return nums;
    }
}
```