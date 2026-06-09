每次排序的位置都在A数组的最后一个单元
```
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int apoint=m-1;
    int bpoint=n-1;
    int point=m+n-1;
    while(apoint>=0 && bpoint>=0){
        //printf("apoint:  %d  bpoint:  %d\n",apoint,bpoint);
        if(A[apoint]>=B[bpoint]){
            A[point]=A[apoint];
            apoint--;
        }
        else{
            A[point]=B[bpoint];
            bpoint--;
        }
        point--;
    }
    while(bpoint>=0){
        A[point]=B[bpoint];
        point--;
        bpoint--;
    }
}
```
