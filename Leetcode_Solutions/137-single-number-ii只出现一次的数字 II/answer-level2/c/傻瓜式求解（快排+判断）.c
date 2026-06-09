```
int partition(int arr[], int left, int right) {
	int j = left, i;
	int val = arr[right];
	int temp;
	for (i = left; i < right; i++) {
		if (arr[i] < val) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
	}
	arr[right] = arr[j];
	arr[j] = val;
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

int singleNumber(int* nums, int numsSize){
    if(numsSize==1){
        return nums[0];
    }
    int temp=nums[0];
    quickSort(nums,0,numsSize-1);
    if(nums[0]!=nums[1]){
        return nums[0];
    }   
    if(nums[numsSize-1]!=nums[numsSize-2]){
        return nums[numsSize-1];
    }
    for(int i=1;i<numsSize-1;i++){
        if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
            temp = nums[i];
            break;
        }
    }
    return temp;
}

```
