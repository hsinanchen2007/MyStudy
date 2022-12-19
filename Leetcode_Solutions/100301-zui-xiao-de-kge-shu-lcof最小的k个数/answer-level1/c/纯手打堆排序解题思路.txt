### 解题思路
##虽然官方答案很简约，直接用了接口实现。但是对于我这种小白来说还是想要多了解实现的原理。
##希望能给想了解具体思路的朋友一点帮助。
### 代码

```c
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
	int *anwser = (int *)malloc(sizeof(int) * (k));
    if(k == 0){
        *returnSize = 0;
        return anwser;
    }

	heapInsert(arr, anwser, k);
	for (int i = k; i < arrSize; i++) {
		if (arr[i] < anwser[0]) {
			## 直接覆盖根节点，并进行堆排序
			anwser[0] = arr[i];
			heapify(anwser, 0, k);
			
		}
	}
    *returnSize = k;
	return anwser;
}

### 首先将k个数存入数组中，并对其进行堆的构造。（每插入一个数据，就迭代检查比较其父节点）
void heapInsert(int *arr, int *anwser, int size) {
	for (int i = 0; i < size; i++) {
		anwser[i] = arr[i];
		int insertIndex = i;
		int fatherIndex = (i - 1) / 2;
		while (anwser[insertIndex] > anwser[fatherIndex]) {
			swap(anwser, insertIndex, fatherIndex);
			insertIndex = fatherIndex;
			fatherIndex = (insertIndex - 1) / 2;
		}
	}
}

void swap(int *arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

## 将根节点与其最大的子节点比较，并交换
void heapify(int *arr, int index, int size) {
	int leftIndex = index * 2 + 1;
	int rightIndex = index * 2 + 2;
	
	int lastIndex;
	while (leftIndex < size) {
		if (rightIndex < size && arr[rightIndex] > arr[leftIndex]) {
			lastIndex = rightIndex;
		}
		else
			lastIndex = leftIndex;
		if (arr[lastIndex] > arr[index]) {
			swap(arr, lastIndex, index);
			index = lastIndex;
		}
		else {
			break;
		}
		
		leftIndex = index * 2 + 1;
		rightIndex = index * 2 + 2;
	}

}
```