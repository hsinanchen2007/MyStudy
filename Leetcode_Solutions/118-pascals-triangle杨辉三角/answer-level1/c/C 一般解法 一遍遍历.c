一般解法
虽然用了两重循环，但对所有的元素只遍历了一遍。
时间O(n)空间O(n)
**注释翻译：**
/ * numrRows为输入的行数。
  * returnSize为输出的行数。
  * returnColumnSizes为返回每行的元素个数的数组。
  * 注意：返回的数组和columnSizes数组都必须被分配，假设调用者调用了free（）。
  * /
### 代码

```c
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i,v,**arr;
    arr = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    *returnSize = numRows;

	for(int i=0;i<numRows;i++){
        (*returnColumnSizes)[i] = i+1; 
        arr[i] = (int *)malloc(sizeof(int)*(i+1));
        arr[i][0] = arr[i][i] = 1;
        for(int v=1;v < i;v++) arr[i][v] = arr[i-1][v-1] +arr[i-1][v];
	}
    return arr;
}
```