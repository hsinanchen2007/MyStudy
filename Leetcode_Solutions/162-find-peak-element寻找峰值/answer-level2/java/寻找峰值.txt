```
    public int findPeakElement(int[] nums) {
        int len = nums.length, l=0, r=len-1;
        while(l < r){
            int mid = (l+r) >> 1;
            if(mid == len-1 || nums[mid] > nums[mid+1]) r = mid;
            else l = mid+1;
        }
        
        return l;
    }
```
