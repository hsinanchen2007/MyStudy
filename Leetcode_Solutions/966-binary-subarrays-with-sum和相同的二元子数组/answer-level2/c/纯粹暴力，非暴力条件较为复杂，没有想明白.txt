```
int numSubarraysWithSum(int* A, int ASize, int S){
    int left;
    int right;
    int sumOfList;
    int ans = 0;

    for (left = 0; left < ASize; left++) {
        sumOfList = 0;
        for (right = left; right < ASize; right++) {
            sumOfList = sumOfList + A[right];
            if (sumOfList == S) {
                ans++;
            } else if (sumOfList > S) {
                sumOfList = 0;
                break;
            }
        }

        if ((sumOfList < S) && (right == ASize)) {
            break;
        }
    }

    return ans;
}
```
