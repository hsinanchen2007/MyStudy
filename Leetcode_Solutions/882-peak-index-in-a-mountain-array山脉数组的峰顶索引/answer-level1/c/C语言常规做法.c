```c
int peakIndexInMountainArray(int* A, int ASize){
    short i=0;
    while(A[i]<A[i+1]) i++;
    return i;
}
```