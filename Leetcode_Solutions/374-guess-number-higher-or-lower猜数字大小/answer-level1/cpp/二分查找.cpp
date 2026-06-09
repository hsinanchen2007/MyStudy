```
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long l = 1;
        long h = n;
        int a = 0;
        long m = 0;
        while(l<h)
        {
            m = (l+h)/2;
            a = guess(m);
            if(a == -1)
            {
                h = m-1;
            }
            else if(a == 1)
            {
                l = m+1;
            }
            else
            {
                return m;
            }
        }
        return l;
    }
};
```
