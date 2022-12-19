执行结果：通过
显示详情
执行用时 :48 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了100.00%的用户

![image.png](https://pic.leetcode-cn.com/cc1d6b356944d2db3b223900b559894d2f65d8fab944b5a1a705a3c1aff72187-image.png)

```
int minIncrementForUnique(int* A, int ASize){
    if (A == NULL || ASize == 0) return 0;
    int set[80000] = {0};
    int min = A[0];
    int max = A[0];
    for (int i = 0; i < ASize; ++i) {
        set[A[i]]++; 
        min = A[i] < min ? A[i] : min;
        max = A[i] > max ? A[i] : max;
    }
    int itera = min;
    int cur = min;
    int step = 0;
    while (itera <= max) {
        if (set[itera] <= 1) {
            itera++;
            continue;
        }
        cur = cur > itera ? cur : itera + 1;
        while (set[cur] != 0) { cur++; };
        set[itera]--;
        set[cur]++;
        step += cur - itera;
    }
    return step;
}
```
