
```c
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0, flag = 0, temp = 0;
    for(int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    for(int i = 0; i <= ASize-3; i++) {
        temp += A[i];
        if(sum == 3*temp) {
            flag++;
            temp = 0;
            for(int j = i+1; j <= ASize - 2; j++) {
                temp += A[j];
                if(sum == 3*temp) {
                    flag++;
                    break;
                }
            }
            break;
        }
    }
    return (flag == 2)?true:false;
}
```