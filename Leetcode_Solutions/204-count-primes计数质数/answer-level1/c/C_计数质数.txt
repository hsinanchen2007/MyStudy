### 解题思路
牺牲空间换时间

参考

作者：xu-zhou-geng
链接：https://leetcode-cn.com/problems/count-primes/solution/c-e-la-duo-sai-shai-fa-by-xu-zhou-geng/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
### 代码

```c
int countPrimes(int n){

    int *nums = malloc(sizeof(int) * n);
    for ( int i = 0; i < n; i++)nums[i] = 1;

    for (int i = 2; i*i <= n; i++)
        if (nums[i])
            for(int j=2;j*i<n;++j)
                nums[j*i]=0;

    int res = 0;
    for (int i =  2; i < n; i++)
        res+= nums[i];

    return res;

}