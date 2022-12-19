### 解题思路
这题就要考库函数，不是考什么算法

### 代码

```c
void bubbleSort(int *dataArray,int n){
	for(int i = 0;i < n - 1;i++)
    {	
		int flag = 0;
		for(int j = 0;j < n  -i-1;j++)
        {
			if(dataArray[j] > dataArray[j + 1])
            {
				flag = 1;	
				int temp = dataArray[j];
				dataArray[j] = dataArray[j + 1];
				dataArray[j + 1] = temp;
			}
		}
		if(flag == 0) break;
	}
}

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize > 0)
    {
        bubbleSort(nums,numsSize);
        for(int i = 0;i < numsSize -1;i++)
            if(nums[i] == nums[i + 1])
                return true;
    }
    return false;    
}
```