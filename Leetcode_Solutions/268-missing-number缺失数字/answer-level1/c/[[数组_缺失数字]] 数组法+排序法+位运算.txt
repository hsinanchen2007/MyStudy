创建一个标记数组。初值全部赋0，下标与nums中数字对应。先遍历一次nums，出现过的数字再标记数组中该下标赋1.
最后遍历一次标记数组，还是0的元素就是缺失数字。
```c
int missingNumber(int* nums, int numsSize){
	int *a=(int*)calloc(sizeof(int),(numsSize+1));
	for(int i=0;i<numsSize;i++){
        a[(nums[i])]=1;
    }
	for(int i=0;i<numsSize+1;i++){
		if(a[i]==0) return i;
	}
    return 0;
}
```

排序法，采用qsort函数先排序再遍历缺少哪个元素。
```c
int compare(const void *a,const void*b){
	return *(int*)a - *(int*)b;
} 
int missingNumber(int* nums, int numsSize){	
	qsort(nums,numsSize,sizeof(int),compare);
	if(nums[0]!=0) return 0;
	if(nums[numsSize-1]!=numsSize) return numsSize;
	for(int i=1;i<numsSize;i++){
		if(nums[i]-nums[i-1]==2){
			return nums[i]-1;
		}
	}
    return 0;
}
```

位运算中的异或（XOR）^：n^n=0 0^n=n。
让sum先等于numsSize是因为，应该出现的数字比实际出现的多一个。在i =0 到i < numsSize的循环中，i不会等于numsSize，只能我们手动添加。
missing​=4∧(0∧0)∧(1∧1)∧(2∧3)∧(3∧4)
=(4∧4)∧(0∧0)∧(1∧1)∧(3∧3)∧2
=0∧0∧0∧0∧2=2
```c
int missingNumber(int* nums, int numsSize){
    int sum = numsSize;
    for(int i = 0; i < numsSize; i++){
        sum ^= i ^ nums[i];
    }
    return sum;
}
```