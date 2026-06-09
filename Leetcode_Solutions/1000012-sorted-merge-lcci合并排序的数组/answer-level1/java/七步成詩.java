### 思路

i指针放在A的屁股上
a指针放在A最后一个元素上
b指针放在B最后一个元素上

比较a和b，谁大把谁放进i
如果a到头了b没到头，把剩下的b放完
如果b到头了a没到头，啥也不做

### 代码

```
public void merge(int[] A, int m, int[] B, int n) {
    int aa = m-1, bb = n-1, i = A.length-1;
    while(aa >= 0 && bb >= 0)
        A[i--] = A[aa] > B[bb] ? A[aa--] : B[bb--];
    while(bb >= 0)
        A[i--] = B[bb--];
}
```
