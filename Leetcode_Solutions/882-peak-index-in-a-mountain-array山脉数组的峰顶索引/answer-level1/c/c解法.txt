### 解题思路
此处撰写解题思路

### 代码

```c
int peakIndexInMountainArray(int* A, int ASize){
    int i;
    for(i=0; i < ASize-1; ++i)
    {
        if(A[i] > A[i+1]){
            break;
        }
    }
    return i;
}
```