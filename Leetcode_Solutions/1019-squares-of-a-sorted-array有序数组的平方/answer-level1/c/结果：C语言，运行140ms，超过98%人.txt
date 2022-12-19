思路：利用数组索引，指向第一个正数与负数，随后通过左右移动即可。
```
int* sortedSquares(int* A, int ASize, int* returnSize){
    int * p = (int*)malloc(sizeof(int)*ASize);
    *returnSize = ASize;
    int index = 0;
    while(index<ASize&&A[index]<0){
        index++;
    }

    int left_index = index-1;
    int num = 0;
    while(left_index>=0&&index<ASize){
        if(A[left_index]+A[index]<0){
            p[num] = A[index]*A[index];
            index++;
        }
        else{
            p[num] = A[left_index]*A[left_index];
            left_index--;
        }
        num++;
    }

    while(left_index>=0){
        p[num] = A[left_index]*A[left_index];
        left_index--;
        num++;
    }

    while(index<ASize){
        p[num] = A[index]*A[index];
        index++;
        num++;
    }
    return p;
}
```
