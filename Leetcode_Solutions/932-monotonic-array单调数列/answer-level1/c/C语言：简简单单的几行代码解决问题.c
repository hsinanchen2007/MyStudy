
```
bool isMonotonic(int* A, int ASize){
    if (ASize <= 2)                                                         return true;
    int i = 0;
    for (; i < ASize-1; ++i)                             if (A[i] != A[i+1])       break;
    if (i >= ASize-1)                                                       return true;
    if (A[i] > A[i+1]) for (int i = 0; i < ASize-1; ++i) if (A[i] < A[i+1]) return false;
    else               for (int i = 0; i < ASize-1; ++i) if (A[i] > A[i+1]) return false;

    return true;
}
```
