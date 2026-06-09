```
class Solution {
public:
    bool isHappy(int n) {
        int f = n;
        int s = n;
        do{
            s = calc(s);
            f = calc(calc(f));
        }while(s != f);
        return s==1;
    }
    int calc(int n)
    {
        int sum = 0;
        int m = 0;
        while(n > 0)
        {
            m = n % 10;
            sum += m * m;
            n /= 10;
        }
        return sum;
    }
};
```
