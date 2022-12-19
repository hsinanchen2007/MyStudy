java版本        //ps: 注意超出int最大值
```
class Solution {
     int M = (int)1e9 +7;

    public int checkRecord(int n){
        long P = 1;     //最新记录为P,且没有A      PS:A = P;
        long AP = 0;    //最新记录为P,且有A
        long L = 1;     //最新记录为L,且没有A
        long LL = 0;    //最新记录为LL,且没有A
        long AL = 0;    //最新记录为L,且有A
        long ALL = 0;   //最新记录为LL,且有A
        long A = 1;     //最新记录为A

        for(int i=2;i<=n;i++){
            long a = (P + L + LL) % M;            //#如果第i次记录是P
            long b = (AP + AL + ALL + A) % M;     //#如果第i次记录是P
            long c = P;                           //#如果第i次记录是L
            long d = L;                           //#如果第i次记录是L
            long e = (AP + A) % M;                //#如果第i次记录是L
            long f = AL;                          //#如果第i次记录是L
            long g = (P + L + LL) % M;            //#如果第i次记录是A

            P = a;
            AP = b;
            L = c;
            LL = d;
            AL = e;
            ALL = f;
            A = g;
        }
        return (int)(P + AP + L + LL + AL + ALL + A) % M;
    }
}
```

