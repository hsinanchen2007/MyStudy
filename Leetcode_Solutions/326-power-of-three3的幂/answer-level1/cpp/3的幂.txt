**1.递归**
```c
bool isPowerOfThree(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return (n % 3 == 0) && isPowerOfThree(n / 3);
}
```
**2.3进制+正则**
```
class Solution {
public:
    string ten2three(int n)
    {
        string s;
        int t;
        do{
            t = n % 3;
            s += t + '0';
            n /= 3;
        }while(n != 0);
        reverse(s.begin(), s.end());
        return s;
    }

    bool isPowerOfThree(int n) {
        regex pat("^10*$");
        string s = ten2three(n);
        return regex_match(s, pat);
    }
};
```