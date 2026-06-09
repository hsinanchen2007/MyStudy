### 解题思路
加油!!

### 代码

```c


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	int temp = 0;
	
	for(int i = 0; i < k; i++)
	{
		for(int j = i+1; j < arrSize; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}		 
	} 
	
	*returnSize = k;
	return arr;
} 
```