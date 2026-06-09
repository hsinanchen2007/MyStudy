
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize){
    int left = 0, right = 0;
    int TotalShiftCnt = 0, currentShiftCnt,dupCnt;

    while (left < numsSize) {
        dupCnt = 1;
        currentShiftCnt = 0;
        while ((right < numsSize) && (nums[left] == nums[right])) {
            right++;
            if (dupCnt++ > 2) {
                currentShiftCnt++;
            }
        }
        if (TotalShiftCnt != 0) {
            for (int i = left; i < right; i++) {
                nums[i - TotalShiftCnt] = nums[i];
            }
        }
        TotalShiftCnt += currentShiftCnt;
        left = right;
    }
}