### 解题思路
折半插入，从后向前扫描，每次循环直接移动到位，减少移动次数

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int mid = 0;
    int i = 0 , j = m-1 ;
    int low = 0 ,high = m-1;
    for(i=n-1;i>=0;i--){ //折半插入
        while(low<=high){
            mid = (low + high) / 2;
            if(A[mid]>B[i]) high = mid - 1;
            else low = mid + 1;
        }
        while(j>=low){ //移动插入位置后的数据
            *(A+j+i+1)=*(A+j);
            j--;
        }
        *(A+j+i+1)=*(B+i);
        high = low-1; //更新并缩小查找范围
        low = 0;
    }
}
```