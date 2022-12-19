int findLucky(int* arr, int arrSize){
    if (arr == NULL || arrSize == 0) {
        return -1;
    }
    int HashMap[501] = {-1};
    int max = -1;
    int retMax = -1;

    for (int i = 0; i < arrSize; i++) {
        HashMap[arr[i]]++;
        max = max < arr[i] ? arr[i] : max;
    }
    for (int i = 0; i <= max; i++) {
        if (HashMap[i] == i) {
            retMax = retMax < i ? i : retMax;
        }
    }
    return retMax == -1 ? -1 : retMax;
}
