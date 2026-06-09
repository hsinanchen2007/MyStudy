```
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    bool *ret;
    int sum = 0;
    *returnSize = ASize;
    ret = (bool *)malloc(sizeof(bool)*ASize);
    for (int i = 0;i < ASize;i++){
        sum = sum*2 + A[i];
        sum = sum % 10;
        if (sum % 5){
            ret[i] = false;
        }else{
            ret[i] = true;
        }
    }
    return ret;
}

```
