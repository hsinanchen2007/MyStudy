G表示格雷编码，B表示二进制数
第i位格雷编码为 G[i] = B[i+1] xor B[i]

        for(int i=0; i<(1<<n); ++i)
        {
            res[i] = i^(i>>1);
        }
生成格雷码