```
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        unsigned long ab=(unsigned long)a*(unsigned long)b/(unsigned long)__gcd(a,b);
        unsigned long ac=(unsigned long)a*(unsigned long)c/(unsigned long)__gcd(a,c);
        unsigned long bc=(unsigned long)c*(unsigned long)b/(unsigned long)__gcd(c,b);
        unsigned long abc=ab*(unsigned long)c/__gcd(ab,(unsigned long)c);

        unsigned l=0;
        unsigned r=INT_MAX;//2*1e9+1;
        while(l<r)
        {
            unsigned mid=(l+r)>>1;
            int tmp=mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc;
            if(tmp<n)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};
```
