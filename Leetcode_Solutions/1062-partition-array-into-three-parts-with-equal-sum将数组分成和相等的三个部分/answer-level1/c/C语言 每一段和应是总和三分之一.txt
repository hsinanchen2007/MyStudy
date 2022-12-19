```
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    int i, j;
    for(i = 0; i < ASize; i++) {
        sum += A[i];
    }
    int flag[2] = {0};
    
    int sum1 = 0;
    int sum3 = 0;
    for(i = 0; i < ASize - 2; i++) {
        sum1 += A[i];
        if(sum == 3 * sum1) {
            flag[0] = 1;
            break;
        }
    }

    for(j = ASize - 1; j > i + 1; j--) {
        sum3 += A[j];
        if(sum == 3 * sum3) {
            flag[1] = 1;
            break;
        }
    }

    if(flag[0] == 1 && flag[1] == 1){
        return true;
    } else {
        return false;
    }    
}
```
