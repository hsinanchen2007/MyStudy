菜鸡的解决方法，虽然不是很高效率，但毕竟做出来了:)

1、先用快速排序，将待处理的数组排序。
2、然后用for循环判断并返回相应的值。

int partition(int arr[], int left, int right) {
    int j = left, i;
    int selectedValue = arr[right];
    int temp;
    for (i = left; i < right; i++) {
        if (arr[i] < selectedValue) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    arr[right] = arr[j];
    arr[j] = selectedValue;
    return j;
}

void quickSort(int arr[], int left, int right) {
    int q;
    if (left < right) {
        q = partition(arr, left, right);
        quickSort(arr, left, q - 1);
        quickSort(arr, q + 1, right);
    }
}

int findDuplicate(int* nums, int numsSize){
    if(numsSize==0){
        return -1;
    }
    quickSort(nums,0,numsSize-1);
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]==nums[i+1]){
            return nums[i];
        }
    }
    return false;
}