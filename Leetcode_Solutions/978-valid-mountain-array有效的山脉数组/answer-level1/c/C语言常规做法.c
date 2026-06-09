```c
bool validMountainArray(int* A, int ASize){
    short i=0;
    while(i+1<ASize&&A[i+1]>A[i]) i++;
    if(i==0||i==ASize-1) return 0;
    while(i+1<ASize&&A[i+1]<A[i]) i++;
    return i==ASize-1;
}
```