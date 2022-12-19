```
class Solution {
public:
    int rotatedDigits(int N) {
        int mp[] = {0,1,2,3,3,3,4,5,5,6}; //all
        int mp2[] = {0,1,2,2,2,2,2,2,2,3}; //single
        int flag[] = {0,0,1,2,2,1,1,2,0,1}; //0,single, 1,ok, 2, bad
        int ret = N;
        int base = 0;
        int mod = 0;
        int n = 0;
        while(ret>0)
        {
            ret /= 10;
            base++;
        }
        int single = 1;
        while(base>0)
        {
            mod = pow(10, base-1);
            n = N/mod;
            ret += mp[n] * pow(7, base-1);
            if(single == 1)
            {
                ret -= mp2[n] * pow(3, base-1);
                if(flag[n] != 0)
                {
                    single = 0;
                }
            }
            if(flag[n] == 2)
                break;
            N %= mod;
            base--;
        }
        if(flag[n] == 1 || (flag[n] == 0 && single == 0))
            ret++;
        return ret;
    }
};
```
