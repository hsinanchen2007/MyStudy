![294A2C9E-6E5B-41BC-910A-E1D29A14819B.jpeg](https://pic.leetcode-cn.com/0499698786a8a925c19e6a0e5423aed848d297a5c2ecc3dad709f90c3f05602d-294A2C9E-6E5B-41BC-910A-E1D29A14819B.jpeg)

```
int numTeams(int* rating, int ratingSize){
    if ((rating == NULL) || (ratingSize < 3)) {
        return 0;
    }
    int i;
    int j;
    int k;
    int returnSize = 0;
    for (i = 0; i < ratingSize; i++) {
        for (j = i + 1; j < ratingSize; j++) {
            for (k = j + 1; k < ratingSize; k++) {
                if (((rating[i] < rating[j]) && (rating[j] < rating[k])) 
                    || ((rating[i] > rating[j]) && (rating[j] > rating[k]))) {
                    returnSize++;
                }
            }
        }
    }

    return returnSize;
}
```
