1.排除5
2.注意超出int范围
```
public int knightDialer(int N) {
        if(N == 1)
           return 10;  
        int mod = 1000000007;
        long a1=1,a2=1,a3=1,a4=1,a6=1,a7=1,a8=1,a9=1,a0=1;
        for(int i=0;i<N-1;i++){
            long A1 = (a8 + a6) % mod;
            long A2 = (a7 + a9) % mod;
            long A3 = (a4 + a8) % mod;
            long A4 = (a3 + a9 + a0) % mod;
            long A6 = (a1 + a7 + a0) % mod;
            long A7 = (a2 + a6) % mod;
            long A8 = (a1 + a3) % mod;
            long A9 = (a2 + a4) % mod;
            long A0 = (a4 + a6) % mod;

            a1 = A1;
            a2 = A2;
            a3 = A3;
            a4 = A4;
            a6 = A6;
            a7 = A7;
            a8 = A8;
            a9 = A9;
            a0 = A0;
        }
        return (int)((a1+a2+a3+a4+a6+a7+a8+a9+a0) % mod);
    }
```
