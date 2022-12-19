### 解题思路
此处撰写解题思路
我的铁憨憨解法，我好好学习算法和数据结构，坚持每天一刷，先把B放到A中，然后对A使用最简单的冒泡排序，我冒泡排序还想了半天，哎，菜啊，不说了，我想办法再去优化优化冒泡排序去
### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    //方法1：直接将B数组插入到A中，然后重新进行排序
    for (int i = 0; i < n; ++i){
        A[m+i] = B[i];
    }
    //重排序，采用最简单的冒泡排序，第一层循环是有多少个数需要比较，第二层循环是每个数需要比较的次数。
    for(int i = 0; i < ASize -1; ++i) {
        for (int j = 0; j < ASize - 1 - i; ++j) {
            if (A[j] > A[j + 1]) {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp; 
            }
        }
    }

    for(int q = 0; q < ASize; ++q) {
        printf("%d", A[q]);
    }
    printf("\n");
}
```