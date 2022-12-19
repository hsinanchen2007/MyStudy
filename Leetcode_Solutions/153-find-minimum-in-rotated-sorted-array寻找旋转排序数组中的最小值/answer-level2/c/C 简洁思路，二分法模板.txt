int findMin(int* nums, int numsSize){
    if(nums == NULL) return -1;
     int len = numsSize;
        if (len == 0) {
            return -1;
        }

        int left = 0;
        int right = len - 1;
        while (left < right) {

            int mid = left+ ((right- left) / 2);
            printf("l %d r %d m%d \n",left,right,mid);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
}