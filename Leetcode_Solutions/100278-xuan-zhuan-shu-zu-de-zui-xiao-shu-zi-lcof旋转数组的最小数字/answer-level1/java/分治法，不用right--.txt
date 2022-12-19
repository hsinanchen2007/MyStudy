直接解释代码，如果数组无重复元素，和153题一样，直接二分；
如果含重复元素导致mid和left,right都相等，则在[left,mid-1]和[mid+1,right]里都进行二分；
其实就是加了一句判断而已
```
public int minArray(int[] numbers) {
        return help154(numbers,0,numbers.length-1);
    }
    private int help154(int nums[],int start,int end){
        if(start+2>end) return nums[start]>nums[end]?nums[end]:nums[start];
        int l = start,r = end,mid = (l+r)/2;
        while(l<=r){
            mid = (l+r)/2;
            if(mid==0) return nums[mid]>nums[mid+1]?nums[mid+1]:nums[mid];
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return nums[mid+1];
            else if (nums[mid] < nums[mid - 1])
                return nums[mid];
            if(nums[mid]==nums[start]&&nums[mid]==nums[end])
                return Math.min(help154(nums,start,mid-1),help154(nums,mid+1,end));
            if(nums[mid]>nums[r]) l = mid+1;
            else r = mid-1;
        }
        return nums[mid];
    }
```
