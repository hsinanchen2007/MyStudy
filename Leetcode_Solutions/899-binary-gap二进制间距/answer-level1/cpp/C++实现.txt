```
class Solution {
public:
    int binaryGap(int N) {
        int res = 0, count = -1, ones = 0;
        while(N>0)
        {
            count++;
            if(N % 2 == 1)
            {
                ones++;
                if(ones>1 && count>res)
                    res = count;
                count = 0;
            }        
            N = N / 2;
        }
        return res;
    }
};
```