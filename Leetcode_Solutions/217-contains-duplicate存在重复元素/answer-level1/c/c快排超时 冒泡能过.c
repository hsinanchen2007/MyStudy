### 解题思路
哭了 自己写的快排超时 冒泡缺没超时o(╥﹏╥)o

### 代码

```c
#define bool int
#define false 0
#define true 1
int partition(int* nums,int low,int high){
    int pivot = nums[low];
    int i = low,j = high;
    while(i < j){
        while(i < j&&pivot <= nums[j]) j--;
        if(i < j){
            nums[i] = nums[j];
            i++;
            while(i < j&&pivot >= nums[i]) i++;
            if(i < j){
                nums[i] = nums[j];
                j--;
            }
        }
    }
    nums[i] = pivot;
    return i;
}
void quickSort(int* nums,int low,int high){
    int pivot;
    if(low < high){
        pivot = partition(nums,low,high);
        quickSort(nums,low,pivot - 1);
        quickSort(nums,pivot + 1,high);
    }
}

void bubbleSort(int *dataArray,int n){
	int flag = 0;
	int i,j,temp;
	for(i = 0;i < n - 1;i++){	//共需要n - 1趟排序
		flag == 0;	//立flag
		for(j = 0;j < n  - 1;j++){	//每趟从第一个位置开始，与后一个位置两两比较
			if(dataArray[j] > dataArray[j + 1]){
				flag = 1;	//出现交换则将flag设为1
				temp = dataArray[j];
				dataArray[j] = dataArray[j + 1];
				dataArray[j + 1] = temp;
			}
		}
		if(flag == 0) break;//一趟比较没有发生变化，则排序完成
	}
}

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize > 0){
        bubbleSort(nums,numsSize);
        for(int i = 0;i < numsSize -1;i++){
            if(nums[i] == nums[i + 1]) return true;
        }
    }
    return false;    
}

```