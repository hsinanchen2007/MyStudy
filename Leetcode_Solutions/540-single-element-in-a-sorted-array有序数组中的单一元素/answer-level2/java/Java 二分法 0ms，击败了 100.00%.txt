因为是有序数组，所以可以用二分法。思路：取数组中间的数，当中间数的下标为奇数，说明前后元素的个数为奇数，偶数则剩余个数为偶数。奇数时：当nums[h]等于[h+1],唯一数处于前h-1,反之处于后h+1。偶数时：当nums[h]等于[h+1]，唯一数处于后h+2,反之处于前h.(就是要保证剩余查找元素个数奇数)
```
class Solution {
    public int singleNonDuplicate(int[] nums) {
       int l=0,r=nums.length-1;
       while(l<r){
           int h=(r+l)/2;
           if(h%2==1){
               if(nums[h]==nums[h+1])
                   r=h-1;
               else
                   l=h+1;
           }else{
               if(nums[h]==nums[h+1])
                   l=h+2;
               else
                   r=h;
           }
       }
        return nums[l];
    }
}
```



