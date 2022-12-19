![DD348F89-814D-4701-B648-A5F16FB72FB7.jpeg](https://pic.leetcode-cn.com/306fb44f3b10ab489bd7bac270fa34162cfc4349bcfaa9b5b11d8ad47ce5f598-DD348F89-814D-4701-B648-A5F16FB72FB7.jpeg)

```
int SubFunc(int a, int b)
{
    int returnVal;
    if (a - b < 0) {
        returnVal = b - a;
    } else {
        returnVal = a - b;
    }
    return returnVal;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    if ((arr1 == NULL) || (arr1Size == 0) || (arr2 == NULL) || (arr2Size == 0)) {
        return 0;
    }
    int returnCount = 0;
    int i;
    int j;
    for (i = 0; i < arr1Size; i++) {
        for (j = 0; j < arr2Size; j++) {
            if (SubFunc(arr1[i], arr2[j]) <= d) {
                goto _END_;
            }
        }
        returnCount++;
        _END_:
        ;
    }

    return returnCount;
}
```
