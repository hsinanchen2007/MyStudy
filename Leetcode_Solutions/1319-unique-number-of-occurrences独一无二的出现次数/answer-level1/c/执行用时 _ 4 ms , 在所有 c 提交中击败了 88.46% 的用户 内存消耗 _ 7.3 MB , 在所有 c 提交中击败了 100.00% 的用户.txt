int rule(const void *p, const void *q)
{
    return (*(int *)p - *(int *)q);
}
bool uniqueOccurrences(int* arr, int arrSize){
        int tmp[arrSize];
    qsort(arr, arrSize, sizeof(int), rule);
    int j = 0;
    int temp = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            tmp[j] = i + 1 - temp;        
            temp = i + 1;
            j++;
        }    
    } 
    tmp[j] = arrSize - temp;
    qsort(tmp, j + 1, sizeof(int), rule); 
    for (int i = 0 ; i < j; i++) {
        if (tmp[i] == tmp[i + 1])
            return false;
    }
    return true;
}