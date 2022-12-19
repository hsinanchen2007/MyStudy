```
int peakIndexInMountainArray(int* A, int ASize)
{
    if (!A || ASize < 3) {
        return 0;
    }
    int max = INT_MIN;
    int maxI = INT_MIN;

    for (int i = 1; i < ASize - 1; i++) {
        if (A[i] > max) {
            max = A[i];
            maxI = i;
        }
    }
    return maxI;
}

```
