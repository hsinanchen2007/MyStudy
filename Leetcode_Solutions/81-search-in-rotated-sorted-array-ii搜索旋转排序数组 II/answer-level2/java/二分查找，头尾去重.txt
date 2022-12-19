    public boolean search(int[] nums, int target) {
        return search(0, nums.length-1, nums, target);
    }

    public boolean search(int start, int end, int[] nums, int target) {
        if(start==end) return nums[start] == target;
        if(start>end) return false;
        int mid = (start+end)/2;
        if(nums[start]==target||nums[end]==target||nums[mid]==target) return true;
        if(start+1==end) return false;
        int left = mid+1;
        int right = mid-1;
        if((left<nums.length&&nums[left]==target)||(right>=0&&nums[right]==target)) return true;
        while(right-1>=start&&nums[right-1]==nums[mid])right--;
        while(start+1<=right&&nums[start+1]==nums[start])start++;
        while(end-1>=left&&nums[end-1]==nums[end])end--;
        while(left+1<=end&&nums[left+1]==nums[left])left++;

        if((nums[start]<=nums[right]&&nums[right]>=target&&nums[start]<=target)||(nums[start]>nums[right]&&(nums[start]<=target||target<=nums[right]))) {
            return search(start, right, nums, target);
        } else {
            return search(left, end, nums, target);
        }
    }