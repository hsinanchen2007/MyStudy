### 解题思路
相同余数的个数里取2个数进行组合，余数是0时，每个数本身就能被K整除也要加上。 

### 代码

```c
int GetCombCount(int n)
{
    //组合数C(n, 2)
    return n * (n - 1) / 2;
}

int subarraysDivByK(int* A, int ASize, int K){
    if (K == 0 || ASize == 0) {
        return 0;
    }

    int count = 0;
    int sum = 0;
    /*
    //暴力超时：66 / 73
    for (int i = 0; i < ASize; i++) {
        sum = 0;
        for (int j = i; j < ASize; j++) {
            sum += A[j];
            if (sum % K == 0) {
                count++;
            }
        }
    }
    */

    //统计出共有多少个前缀和是k的倍数
    int yushu = 0; //余数相同的前缀和是K的倍数: a*k - b*k = c*k
    int *mod = malloc(sizeof(int) * K);
    memset(mod, 0, sizeof(int) * K);
    for(int i = 0; i < ASize; i++) {
        sum += A[i]; //i的前缀和
        yushu = sum % K;
        if (yushu < 0) {
            yushu += K;//负数的余数转成正数
        }
        mod[yushu]++;
    }

    //相同余数的2个数组合都是k的倍数
    for (int i = 0; i < K; i++) {
        if (mod[i] > 0) {
            count += GetCombCount(mod[i]);
        }
    }
    if (mod[0] > 0) {
        //余数是0时，每个数本身就能被K整除了
        count += mod[0];
    }
    free(mod);

    return count;
}
```