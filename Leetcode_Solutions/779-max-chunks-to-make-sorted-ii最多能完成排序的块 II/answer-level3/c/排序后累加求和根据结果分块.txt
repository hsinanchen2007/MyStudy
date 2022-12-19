```c
int maxChunksToSorted(int* arr, int arrSize){
    int *arrOrder = malloc(arrSize * sizeof(arr));
    int cal = 0;
    unsigned int sum1 = 0, sum2 = 0;
    for(int i = 0; i < arrSize; i++)
        arrOrder[i] = arr[i];
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = i + 1; j < arrSize; j++)
        {
            if(arrOrder[i] > arrOrder[j])
            {
                arrOrder[i] = arrOrder[i] ^ arrOrder[j];
                arrOrder[j] = arrOrder[i] ^ arrOrder[j];
                arrOrder[i] = arrOrder[i] ^ arrOrder[j];
            }
        }
    }
    for(int i = 0; i < arrSize; i++)
    {
        sum1 += arrOrder[i];
        sum2 += arr[i];
        if(sum1 == sum2)
            cal++;
    }
    free(arrOrder);
    return cal;
}
```