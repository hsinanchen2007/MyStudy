### 解题思路
以0为对称中心的数之和为0。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    *returnSize=n;
    int *b;
    int i=1;
    b=(int*)malloc(n*sizeof(int));
    if(n==1)
    b[0]='0';

        b[0]=(-1)*(n/2);
        while(i<n){
            if(i==(n+1)/2&&(n%2==0)){//区分奇偶，跳过0
                b[i]=b[i-1]+2;
                i++;
            continue;}
            b[i]=b[i-1]+1;
            i++;
        }
    return b;

}
```

 - 用时12ms,内存消耗7.8MB。