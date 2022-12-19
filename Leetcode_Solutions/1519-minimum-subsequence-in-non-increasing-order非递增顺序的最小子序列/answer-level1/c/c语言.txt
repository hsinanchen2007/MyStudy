### 解题思路
排序，排完序后从后头加判断是否大于前头

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void Shell_Sort(int* A, int N)
{
	int D, P, i, Temp;
	for(D = N/2;D>0;D/=2)			//希尔排序的增量（可自己定义）(Hibbard,Sedgewick增量);
	{
		
		for(P = D; P < N; P++)			//插入排序
		{
			Temp = A[P];
			for(i = P; i>=D && A[i-D]>Temp; i -= D)
				A[i] = A[i-D];
			A[i] = Temp;
		}
	}
}
int groupSum(int *A, int N){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += A[i];
    }
    return sum;
}
int* minSubsequence(int* nums, int numsSize, int* returnSize){
    int size = numsSize - 1, index = 0;;
    int *returnSum = (int *)malloc(sizeof(int *)* numsSize);
    int sum = groupSum(nums, numsSize);
    int Rsum = 0;
    Shell_Sort(nums, numsSize);
    
    while(size >= 0 ){
        if(sum - nums[size] < nums[size] + Rsum){returnSum[index++] = nums[size];break;}
        else{returnSum[index] = nums[size--];Rsum += returnSum[index];sum -= returnSum[index];index++;}
    }
    
    *returnSize = index;
    return returnSum;

}
```