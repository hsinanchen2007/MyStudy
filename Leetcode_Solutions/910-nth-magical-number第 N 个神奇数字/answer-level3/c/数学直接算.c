### 解题思路
此处撰写解题思路

### 代码

```c

int min(int a ,int b){
    if(a <= b)
        return a;
    else 
        return b;
}
int min_pub_num(int A, int B)//最小公倍数
{
    int  temp, i;
    for(i=A; i>0; i=i+A)  {
        if(i%A==0 && i%B==0)
            break;
    }
    return i;
}

int nthMagicalNumber(int N, int A, int B){
    long int ret = 0 ;
    int MOD = 1000000007;
    int L = min_pub_num(A,B);
    int M = L / A + L / B - 1;
    int q = N / M, r = N % M;
    long ans = (long) q * L % MOD;
        if (r == 0)
            return (int) ans;

        int heads[2] = {A, B};
        for (int i = 0; i < r - 1; ++i) {
            if (heads[0] <= heads[1])
                heads[0] += A;
            else
                heads[1] += B;
        }

        ans += min(heads[0], heads[1]);
        return (int) (ans % MOD);
    }

 




```