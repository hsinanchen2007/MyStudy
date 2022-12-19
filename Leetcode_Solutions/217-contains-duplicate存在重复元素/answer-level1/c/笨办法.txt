int CmpFun(const void *p1, const void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;

    return *a - *b;
}

bool containsDuplicate(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return false;
    }

    qsort(nums, numsSize, sizeof(int), CmpFun);
    int i;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            break;
        }
    }

    if (i == numsSize - 1) {
        return false;
    }

    return true;

}