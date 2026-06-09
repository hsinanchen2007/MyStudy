看大部分题解没涉及到具体的数学推导过程，这里详细说下吧
前提
1. 不妨让所有小猪每次都一起喝水，那么小猪一共能喝水R轮，即R = minutesToTest / minutesToDie
2. 不妨假设n只猪在r轮喝水之后最大能判断 `F(n,r)`桶水
    
此时考虑每个桶的情况，由于存在一轮喝水中多只猪一起喝一个桶的情况，因此按照同时被几只猪喝对桶分类
考虑此时有n只猪，在倒数第r轮喝水
1. 同时被n只猪喝，那么假设这桶水有毒，所有猪全死了，如果这类桶数量超过1，显然就无法判断具体是哪一桶了，因此这类桶最多一个(猪全死了就是它有毒)
2. 同时被n-1只猪喝，假设这桶水有毒，死了n-1只猪，那么只剩下一只猪和r-1轮喝水机会，那么这类水桶最多只能有 `C(n,n-1) * F(1,r-1)`个
3. 同时被n-k只猪喝，假设这桶水有毒，死了n-k只猪，那么只剩下k只猪和r-1轮喝水机会，那么这类水桶最多只能有 ` C(n,k) * F(k,r-1)`个
4. 这一轮没有猪喝，那么假设这桶水有毒，只剩下n只猪和r-1轮喝水机会，那么这类桶最多只能有  `C(n,0) * F(n,r-1)`个

第1中情况也可以视作F(0,r-1)，因为如果不给猪的话，最多只能判断一桶水的情况，只剩一桶水时它必有毒
因此得出递推公式
`F(n,r) = C(n,n) * F(0,r-1) + C(n,n-1) * F(1,r-1) + ... + C(n,0) * F(n,r-1)`

标准的动态规划

当然这个公式也可以直接推导
考虑r = 0的情况，即不允许让小猪喝水，那相当于没有小猪，最多判断一桶水，因此 `F(n,0) = F(n-1,0) = ... = F(0,0) = 1`
因此 
`F(n,1) = C(n,n) * F(0,0) + C(n,0) * F(1,0) + ... + C(n,0) * F(n,0) = 2^n`
`F(n,2) = C(n,n) * F(0,1) + C(n,0) * F(1,1) + ... + C(n,0) * F(n,1) = C(n,n) * 2^0 + C(n,0) * 2^1 + ... + C(n,0) * 2^n = (2+1)^n = 3^n`
`...`
`F(n,r) = ... = (r+1)^n`
因此n只小猪r轮最多判断`(r+1)^n`桶水，那么显然，如果桶数已定，`n = ceil(log(buckets)/log(r+1))` （注意向上取整）

    
```
    public int dp(int buckets, int minutesToDie, int minutesToTest) {
        int[][] DP = new int[buckets][2];
        int[][] C = new int[buckets][buckets];

        for (int i = 0; i < buckets; i++) {
            C[i][0] = 1;
            C[i][i] = 1;
            for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
        int curr = 0;
        for (int i = 0; i < buckets; i++) DP[i][curr] = 1;
        int round = minutesToTest / minutesToDie;
        for (int r = 0; r < round; r++) {
            curr = 1 - curr;
            for (int i = 0; i < buckets; i++) {
                DP[i][curr] = 0;
                for (int j = 0; j <= i; j++) {
                    DP[i][curr] += C[i][i - j] * DP[j][1 - curr];
                }
                if (DP[i][curr] >= buckets) {
                    if (r == round - 1) return i;
                    break;
                }
            }
        }
        return 0;
    }

    // 简化后解法
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int round = minutesToTest / minutesToDie;
        if (buckets <= 1) return 0;
        return (int)Math.ceil(Math.log((double)buckets) / Math.log((double)round + 1));
    }
```
