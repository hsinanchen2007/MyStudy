![A3C7D767-C32C-432F-8214-79C15FCBC7C6.jpeg](https://pic.leetcode-cn.com/7a5816ed69482415df092d9ba3434b75a33b3529609c1d5ba999cb8c5cc1cb6a-A3C7D767-C32C-432F-8214-79C15FCBC7C6.jpeg)
```
#define COLSIZE 2

int Cmp(const void *a, const void *b)
{
    if ((*(int **)a)[1] != (*(int **)b)[1]) {
        return (*(int **)a)[1] - (*(int **)b)[1];
    } else {
        return (*(int **)a)[0] - (*(int **)b)[0];   
    }
}

int getKth(int lo, int hi, int k){
    
    int i;
    int tmpVal;
    int cnt;
    if (lo > hi) {
        return 0;
    }
    if (lo == hi) {
        return lo;
    }
    
    int **returnVal = (int **)malloc((hi - lo + 1) * sizeof(int *));
    for (i = lo; i <= hi; i++) {
        cnt = 0;
        returnVal[i - lo] = (int *)malloc(COLSIZE * sizeof(int));
        returnVal[i - lo][0] = i;
        tmpVal = i;
        while (tmpVal != 1) {
            if (tmpVal % 2 == 0) {
                tmpVal = tmpVal / 2;
            } else {
                tmpVal = 3 * tmpVal + 1;
            }
            cnt++;
        }
        //printf("cnt: %d\n", cnt);
        returnVal[i - lo][1] = cnt;
    }
    
    qsort(returnVal, hi - lo + 1, sizeof(returnVal[0]), Cmp);
    
    return returnVal[k - 1][0];
}


```

