bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize <= 2) {
        return false;
    }
    int sum = 0;
    for (int i = 0; i < ASize;i++) {
        sum +=A[i];
    }
    if(sum % 3 != 0) {
        return false;
    }
    int he = sum / 3;
    int count = 0;
    for (int i = 0;i < ASize;i++) {
        count += A[i];
        if (count == he) {
            count = 0;
        }
    }
    if (count == 0) {
        return true;
    }
    return false;
}