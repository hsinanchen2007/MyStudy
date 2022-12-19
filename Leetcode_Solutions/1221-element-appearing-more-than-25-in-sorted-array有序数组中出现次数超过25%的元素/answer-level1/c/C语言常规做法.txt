```c
int findSpecialInteger(int* arr, int arrSize){
    short i=0;
    while(arr[i]!=arr[i+arrSize/4])
        i++;
    return arr[i];
}
```