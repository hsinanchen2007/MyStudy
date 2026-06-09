public int searchInsert(int[] nums, int target) {

        int _length = nums.length -1;
        if (_length == -1) {
            return 0;
        }

        if (nums[_length] < target) {
            return _length +1;
        }

        int right = _length;
        int left = 0;
        int mid;
        while(left<right){
            mid = (right+left)>>1;
            switch (target>nums[mid] ? 0:1){
                case 0:{
                    left = mid + 1;
                    break;
                }
                case 1:{
                    right = mid;

                    break;
                }
                default: return mid;
            }
        }
        return left;
    }