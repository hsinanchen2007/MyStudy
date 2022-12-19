### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void swap(int* arr, int index,int max)
{
	int temp = arr[max];
	arr[max] = arr[index];
	arr[index] = temp;
}

void HeapJust(int* arr,int index, int arrLen)
{
	    //初始化
		int lChild = index * 2 + 1;
		int rChild = index * 2 + 2;
		int max = index;

		if (lChild<arrLen && (arr[lChild]>arr[max]))
		{
			max = lChild;
		}

		if (rChild<arrLen && (arr[rChild]>arr[max]))
		{
			max = rChild;
		}

		//如果最大值是左右结点，则交换
		if (max != index)
		{
			swap(arr, index, max);
			HeapJust(arr, max, arrLen);
		}

}

void HeapSort(int* arr, int arrLen)
{
	//初始化
	for (int index = arrLen / 2 - 1; index >= 0; index--)
	{
		HeapJust(arr, index, arrLen);
	}

	//从上往下交换
	for (int i = arrLen - 1; i >= 0; i--)
	{
		swap(arr, i, 0);
		HeapJust(arr, 0, i);
	}
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    HeapSort(arr,arrSize);
    *returnSize=k;
    int* ans=(int*)malloc(sizeof(int*)*k);
    for(int i=0;i<k;i++){
        ans[i]=arr[i];
    }
    return ans;

}
```