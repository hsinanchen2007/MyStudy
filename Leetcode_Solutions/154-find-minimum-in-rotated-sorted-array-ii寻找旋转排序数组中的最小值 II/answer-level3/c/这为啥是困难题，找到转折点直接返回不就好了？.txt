int findMin(int* nums, int numsSize){
    int num1 = nums[0];
    int spin_pos = 0;
    
    for (spin_pos = 0; spin_pos < numsSize - 1; spin_pos++) {
        if (nums[spin_pos] > nums[spin_pos + 1]) {
            num1 = nums[spin_pos + 1];
            break;
        }
    }
    
    return num1;
}