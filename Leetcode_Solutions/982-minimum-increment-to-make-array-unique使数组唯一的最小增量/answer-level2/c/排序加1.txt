### 解题思路
此处撰写解题思路

### 代码

```c
void quicksort(int start,int end,int *A){
    if(start>=end)
    return;
    int first=start;int last=end;
    int temp=A[first];
    while(first<last){
    while(last>first&&A[last]>=temp){
        last--;
    }
    A[first]=A[last];
    while(first<last&&A[first]<=temp){
        first++;
    }
    A[last]=A[first];}
    A[first]=temp;
    quicksort(start,first-1,A);
    quicksort(first+1,end,A);
}
int minIncrementForUnique(int* A, int ASize){
    if(ASize==0)
    return NULL;
    if(ASize==1)
    return 0;
    quicksort(0,ASize-1,A);
    int diff=0;
    for(int i=1;i<ASize;i++){
        if(A[i]<=A[i-1]){
            int pre=A[i];
            A[i]=A[i-1]+1;
            diff+=A[i]-pre;
        }
    }
    return diff;}
```