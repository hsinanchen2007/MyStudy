```
void rotate(int* nums, int numsSize, int k){

	int remove = k%numsSize;//实际需要移动的次数
	int temp;	
	for(int i = 0 ; i <(numsSize-remove)/2;i++)
	{
		 temp = nums[i];
		nums[i] = nums[numsSize-remove-1-i];
		nums[numsSize-remove-1-i] = temp;
	}

	for(int j =0;j<remove/2;j++ ){
	
		temp = nums[numsSize-remove+j];
		nums[numsSize-remove+j] = nums[numsSize-j-1];
		nums[numsSize-j-1] = temp;
	}

	for(int m = 0 ; m <numsSize/2;m++ )
	{
		temp = nums[m];
		nums[m] = nums[numsSize-m-1];
		nums[numsSize-m-1] = temp;

	}

}
```
