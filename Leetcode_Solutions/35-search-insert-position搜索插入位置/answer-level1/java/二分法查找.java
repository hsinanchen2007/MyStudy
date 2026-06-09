第一次使用暴力方式提交也超快，但是看到需要用二分法来求解，又重新写了一遍，解题如下，只要还是方法返回值需要仔细考虑
二分法在数据量少的情况下和暴力破解法没有多大差别，更多的在于大数据量后，时间复杂度的优势才能显现出来
```
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;

        while(left<=right){
            int mid = (left + right) /2;
            if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;  
            }else{
                return mid;
            }
        }
        return left;
    }
```
