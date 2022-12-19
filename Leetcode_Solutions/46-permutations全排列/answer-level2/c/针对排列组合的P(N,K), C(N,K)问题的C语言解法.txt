### 解题思路
此处撰写解题思路

### 代码

```c

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #if 0
 // this is for  C(n, k)
 #define MAX_SIZE  5000

int cmp(const void * a, const void *b){
	return (*(int *)a - *(int *)b);

}

void add(int num, int * tmp_array){
	int index=tmp_array[0];
	tmp_array[index]=num;
	index++;
	tmp_array[0]=index;

}

void removeint num, int * tmp_array){
	int index=tmp_array[0];
	tmp_array[index]=-1;
	index--;
	tmp_array[0]=index;
}


void backtrack(int **ret_array, int k, int * nums, int numsSize, int *num_total, int *columnSizes, int m, int * tmp_array){
    if(k == m){
        ret_array[*num_total]=(int *)malloc(sizeof(int)*m);
        memcpy(ret_array[*num_total], tmp_array, sizeof(int)*m);
        columnSizes[*num_total]=m;
        int p=*num_total;
        p++;
        *num_total=p;
        return;
    }

    int i=k;
    for(;i<numsSize;i++){
        add(nums[i], tmp_array);
        backtrack(ret_array, i+1, nums, numsSize, num_total,columnSizes, tmp_array);
        remove(nums[i], tmp_array);
    }
}

int** permute(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes){
    int **ret_array=(int **)malloc(sizeof(int *)*MAX_SIZE);
	int  *tmp=malloc(sizeof(int)*(numsSize+1));
	memset(tmp, 0, sizeof(int)*(numsSize+1));
	int num_total=0;
    int *ptr=*returnColumnSizes=(int *)malloc(sizeof(int)*MAX_SIZE);
    memset(ptr, 0, sizeof(int)*MAX_SIZE);
	qsort(nums, numsSize, sizeof(int), cmp);
    backtrack(ret_array, 0, nums, numsSize, &num_total, ptr, k, int * tmp_array);
    *returnSize=num_total;
    return ret_array;
}

#endif


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 // this is for P(n,k)
 #define MAX_SIZE  5000
void swap(int * nums, int k, int i){
    int tmp=nums[k];
    nums[k]=nums[i];
    nums[i]=tmp;
}

void backtrack(int **ret_array, int k, int * nums, int numsSize, int *num_total, int *columnSizes){
    if(k == numsSize){
        ret_array[*num_total]=(int *)malloc(sizeof(int)*numsSize);
        memcpy(ret_array[*num_total], nums, sizeof(int)*numsSize);
        columnSizes[*num_total]=numsSize;
        int p=*num_total;
        p++;
        *num_total=p;
        return;
    }
//choose num from the waiting list of nums
    int i=k;
    for(;i<numsSize;i++){
        // choose num nums[i]
        swap(nums, k, i);
        //k+1
        backtrack(ret_array, k+1, nums, numsSize, num_total,columnSizes);
        // undo the choice of nums[i]
        swap(nums, k, i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret_array=(int **)malloc(sizeof(int *)*MAX_SIZE);
    int num_total=0;
    int *ptr=*returnColumnSizes=(int *)malloc(sizeof(int)*MAX_SIZE);
    memset(ptr, 0, sizeof(int)*MAX_SIZE);
    backtrack(ret_array, 0, nums, numsSize, &num_total, ptr);
    *returnSize=num_total;
    return ret_array;
}
```