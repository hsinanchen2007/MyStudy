void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shiftDown(int *nums, int i, int length)
{
    int child;
    while(i * 2 + 1 < length) {
        child = i * 2 + 1;
        if (child + 1 < length && nums[child] < nums[child + 1]) {
            child += 1;
        }
        if (nums[i] < nums[child]) {
            swap(&nums[i], &nums[child]);
        } else {
            break;
        }
        i = child;
    }
}

void heapSort(int *nums, int length)
{
    if (length <= 1) {
        return;
    }
    int i = length / 2 - 1;
    while (i >= 0) {
        shiftDown(nums, i, length);
        i--;
    }
    i = length - 1;
    while (i > 0) {
        swap(&nums[i], &nums[0]);
        shiftDown(nums, 0, i);
        i--;
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    heapSort(nums, numsSize);
    return nums[numsSize - k];
}