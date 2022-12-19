执行结果：通过
显示详情
执行用时 :4 ms, 在所有 c 提交中击败了60.71%的用户
内存消耗 :6.6 MB, 在所有 c 提交中击败了100.00%的用户

```
int subtractProductAndSum(int n)
{
    if (n <= 0) {
        return 0;
    }

    int temp[10] = {0};
    int len = 0;
    int mul = 1;
    int sum = 0;

    while (n) {
        temp[len++] = n % 10; 
        n = n / 10;
    }
    for (int i = 0; i < len; i++) {
        mul *= temp[i];
        sum += temp[i];
    }
    return mul - sum;
}
```
