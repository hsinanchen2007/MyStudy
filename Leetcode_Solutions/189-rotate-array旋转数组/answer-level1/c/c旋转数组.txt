void rotate(int* nums, int numsSize, int k){
    if(NULL == nums || numsSize <= 1){
        return;
    }
    k %= numsSize;
    reverse(nums,0,numsSize - 1);
    reverse(nums,0,k - 1);
    reverse(nums,k,numsSize - 1);
}

void reverse(int *nums,int start,int end){
    while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}