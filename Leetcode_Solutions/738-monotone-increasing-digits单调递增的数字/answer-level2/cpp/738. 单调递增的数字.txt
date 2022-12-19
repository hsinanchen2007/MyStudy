```
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        auto num= to_string(N);
        int n=num.size();
        int pos=n;
        for(int i=n-1;i>0;--i)
        {
            if(num[i-1]>num[i])
            {
                pos=i;
                --num[i-1];
            }
        }
        for(int i=pos;i<n;++i)
        {
            num[i]='9';
        }

        stringstream s(num);
        int res;
        s>>res;
        return res;
    }
};
```
