看上去是2层循环，实际上内层的while循环只会循环1次（到窗长），后面每次都是移动一次end，移动一次begin，只关注新进窗是否为1，出窗是否为1，改一下和的值即可。
```
int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X)
{
    int sum = 0;
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0) {
            sum += customers[i]; /* 所有为0的和 */
        }
    }
    int begin = 0;
    int end = 0;
    int max = sum;
    while (end < customersSize) {
        while ((end < customersSize) && (end - begin < X)) {
            if (grumpy[end] == 1) {  /* 窗长范围内的1也都计算进去 */
                sum += customers[end];
            }
            if (sum > max) {
                max = sum;
            }
            end++;
        }
        if (grumpy[begin] == 1) {
            sum -= customers[begin]; /* 有1移出窗外，从sum中去掉 */
        }
        begin++;
    }
    return max;
}
```
