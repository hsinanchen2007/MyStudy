$n=rowIndex+1$

$S_{r=1}^{n/2}|C_{n-1}^{r}= \frac{A_{n-1}^{r}}{r!}=\frac{(n-1)!}{r!(n-1-r)!}=\prod_{r=1}^{n/2}\frac{n-r}{r}$

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;
    int *result=(int *)malloc(*returnSize*sizeof(int));
    int i,j = *returnSize/2;;
    result[0]=1;
    if (*returnSize==1) {
        return result;
    }
    result[1]=*returnSize-1;
    for (i=2; i<j; ++i) {
        result[i] = (long long int)result[i-1]*(*returnSize-i)/i;
    }
    i = j-1;
    if (*returnSize%2!=0) {
        result[j] = (long long int)result[j-1]*(*returnSize-j)/j;
        ++j;
    }
    while (i>=0) {
        result[j] = result[i];
        ++j;
        --i;
    }
    return result;
}
```