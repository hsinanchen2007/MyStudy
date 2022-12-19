### 解题思路
快速排序参考的是王道考研数据结构书上的。其实c语言也自带排序函数。
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int partition_sum(int *a,int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot)high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quickSort_sum(int *a,int low,int high){
    if(low<high){
        int pivotpos=partition_sum(a,low,high);
        quickSort_sum(a,low,pivotpos-1);
        quickSort_sum(a,pivotpos+1,high);
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int setsize=0;
    quickSort_sum(nums,0,numsSize-1);
    int p=0;int q=numsSize-1;
    int **output=(int**)malloc(sizeof(int*)*50000);
    *returnColumnSizes=(int*)malloc(sizeof(int)*50000);
    int size=0;
	for(int i=0;i<=numsSize-2;i++){
        if(i!=0&&nums[i-1]==nums[i]){
            continue;
        }
		p=i+1;q=numsSize-1;
		while(p<q){
			if(p!=i+1&&nums[p-1]==nums[p]){
				p++;
			    continue;
			}
			if(q!=(numsSize-1)&&nums[q]==nums[q+1]){
				q--;
				continue;
			}
			int twosum=nums[p]+nums[q];
            int threesum=twosum+nums[i];
            if(threesum==0){
				output[size]=(int*)malloc(sizeof(int)*3);
                output[size][0]=nums[p];
                output[size][1]=nums[q];
                output[size][2]=nums[i];
                (*returnColumnSizes)[size]=3;
                size++;
				p++;q--;
            }
			if(threesum<0){
				p++;
			}
			if(threesum>0){
				q--;
			}
        }
	}
    *returnSize=size;
    return output;
}
```