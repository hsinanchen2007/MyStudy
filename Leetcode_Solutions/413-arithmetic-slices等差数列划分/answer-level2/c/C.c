### 解题思路
 * 遍历每两个相邻数
 * 用这两个数的差，数出以这两个相邻数作为起点所有的等差数列
 *
 * 例如[1,2,3,4,6,8]，数的顺序为
 * [1,2]为起点：[1,2,3], [1,2,3,4]
 * [2,3]为起点：[2,3,4]
 * [3,4]为起点：
 * [4,6]为起点：[4,6,8]
 * [6,8]为起点：
 * 总数为4

### 代码

```c
int countSlices(int *A, int ASize, int tail, int diff) {
    int numSlice = 0;
    for (int i = tail; i+1 < ASize; i++) {
        if (A[i+1] - A[i] != diff) break;
        numSlice++;
    }
    return numSlice;
}

int numberOfArithmeticSlices(int* A, int ASize){
    int numSlices = 0;
    for (int i = 0; i+1 < ASize; i++) {
        numSlices += countSlices(A, ASize, i+1, A[i+1] - A[i]);
    }
    return numSlices;
}
```