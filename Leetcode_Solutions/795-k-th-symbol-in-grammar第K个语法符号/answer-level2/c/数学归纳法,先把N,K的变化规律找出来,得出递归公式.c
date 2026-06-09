### 解题思路
此处撰写解题思路

### 代码

```c
/*
数学归纳法,先把N,K的变化规律找出来,得出递归公式
n 和 k 都要随递归变化
用例充分验证,自己多搞些用例
*/

bool IsLeftHalf(int n, int *k)
{
    int tmp = n > 2 ? (1 << n - 2) : 1;
    if (*k <= tmp) {
        //printf("%s %d:true n=%d, k=%d tmp%d\n",  __func__, __LINE__, n, *k, tmp);
        return true;        
    }
    *k -= tmp;
    //printf("%s %d:false n=%d, k=%d tmp%d\n",  __func__, __LINE__, n, *k, tmp);
    return false;
}

int All(int n, int k)
{
    //printf("%s %d: n=%d, k=%d\n",  __func__, __LINE__, n, k);
    if (n == 1) {
        return 0;
    }
    int k1 = k;
    if (IsLeftHalf(n, &k1)) {
        //printf("%s %d: n=%d, k=%d\n",  __func__, __LINE__, n, k1);
        return All(n - 1, k1);
    }
    return Right(n - 1, k1);
}

int Right(int n, int k)
{
    //printf("%s %d: n=%d, k=%d\n",  __func__, __LINE__, n, k);
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return k == 1 ? 1 : 0;
    }
    int k1 = k;
    if (IsLeftHalf(n, &k1)) {
        return Right(n - 1, k1);
    }
    return All(n - 1, k1);
}

int kthGrammar(int N, int K)
{
    if (N == 1) {
        return 0;
    }

    int ret = All(N, K);
    return ret;    
}
```