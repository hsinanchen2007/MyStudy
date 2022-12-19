### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        // 快排
        quicksort(nums,0,nums.length-1);
        return nums;
    }
    void quicksort(int[] nums,int start,int end){
        if(start>=end) return;
        int solder = nums[start];
        int l = start;
        int r = end;
        while( l<r ){
            while( r>l && nums[r] >= solder ) r--;
            nums[l]=nums[r];
            while( l<r && nums[l] <= solder ) l++; 
            nums[r]=nums[l];
        }
        // 归位
        nums[r] = solder;
        quicksort(nums,start,r-1);
        quicksort(nums,r+1,end);
    }

  
}
```