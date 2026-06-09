![1.png](https://pic.leetcode-cn.com/6442090f016c3cd8d536273e03dc63c9618861f1af51484ffbd0a1ead6ffa5a3-1.png)

### 解题思路
一、将arr1映射到map中；
二、将map中的arr2，按arr1的数量、arr2的顺序，依次放入arr1;
三、将map中剩余的arr1，按升序放入arr1。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
	*returnSize = arr1Size;
	if(arr1Size < 2)
		return arr1;
	int *map = (int*)calloc(1001, sizeof(int)), index = 0;
	for (int i = 0; i < arr1Size; i++)
		map[arr1[i]]++;
	for (int i = 0; i < arr2Size; i++){
		if (map[arr2[i]]){
			while (map[arr2[i]]--)
				arr1[index++] = arr2[i];
		}
	}
	for (int i = 0; i < 1001; i++){
		if (map[i]>0){
			while (map[i]--)
				arr1[index++] = i;
		}
	}
	return arr1;
}
```