bool canJump(int* nums, int numsSize){
    //贪心算法，每次都有的跳，即只跳一步
    int i;
    int current;
    if (numsSize == 0 || nums == NULL) {
        return false;
    }
    if (numsSize == 1) {
        return true;
    }
    current = nums[0];
    for (i = 1; i < numsSize - 1; i++) {
            current--;
            if (current < 0) {
                return false;
            }
            if (current < nums[i]) {
                current = nums[i];
            }
    }
    //跳到倒数第二步看下current是否大于等于1
    if (current < 1) {
        return false;
    }
    return true;
}