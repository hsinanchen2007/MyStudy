### 解题思路
此处撰写解题思路
（1）index指向A的末尾下标，其长度为m + n - 1;
（2）index1表示A的有效元素的下标；
（3）index2表示B的有效元素的下标；
（4）依次判断元素的大小并插入到A数组中；
（5）最后判断一下B数组是否已经遍历完即可

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int index, index1, index2;

    if (B == NULL || n <= 0) {
        return;
    }

    index = m + n -1;
    index1 = m - 1;
    index2 = n - 1;

    while (index1 >= 0 && index2 >= 0) {
        if (A[index1] > B[index2]) {
            A[index] = A[index1];
            index1--;
        } else {
            A[index] = B[index2];
            index2--;
        }
        index--;
    }

    while (index2 >= 0) {
        A[index] = B[index2];
        index--;
        index2--;
    }

}

```