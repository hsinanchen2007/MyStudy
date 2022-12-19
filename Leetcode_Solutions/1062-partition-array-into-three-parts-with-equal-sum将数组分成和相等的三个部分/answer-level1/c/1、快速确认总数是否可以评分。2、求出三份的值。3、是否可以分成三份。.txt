bool canThreePartsEqualSum(int* A, int ASize){
    if (ASize < 3) {
        return false;
    }
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) {
        return false;
    }
    int average = sum / 3;
    sum = 0;
    int part = 1;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
        if (sum == average){
            if ((ASize - i - 1) < (3 - part)) {
                return false;
            }
            sum = 0;
            part += 1;
            if (part == 3) {
                return true;
            }
            
        }
    }
    return false;
}