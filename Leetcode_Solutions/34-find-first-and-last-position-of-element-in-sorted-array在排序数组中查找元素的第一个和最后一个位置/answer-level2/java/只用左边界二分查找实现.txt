本题核心在于查找target元素在nums数组中最左、最右两个边界的位置。大多数题解中解法是写两个查找，一个左边界，一个有边界。其实可以把右边界查找转化为左边界实现。具体实现方法看代码注释。
```
    public int[] searchRange(int[] nums, int target) {
        //查找target元素的最左边位置，即最先出现时的位置。
        int first = binarySearch(nums, target);
        //查找target+1元素，即比target大的最小元素的值的位置，当前值减一，就可以得到target元素的最右边位置。
        int last = binarySearch(nums, target + 1) - 1;
        if(first == nums.length || nums[first] != target){
            return new int[]{-1, -1};
        }else{
            return new int[]{first, Math.max(first, last)};
        }
    }

    //根据nums[mid] == target的值写的啥，判定是左边界二分查找还是右边界。 此处为左边界二分查找。即查找相同元素的最左边元素
    //若为右边界二分查找 当nums[mid] == target时，l = mid + 1; 查找相同元素的最右边元素
    private int binarySearch(int[] nums, int target){
        int l = 0, r = nums.length;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
```
