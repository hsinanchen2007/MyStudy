这题看成是一个26进制的问题，但是与普通的进制不同，将n对26取余后，余数1~25对应'A'~'Y'，而0对应的是'Z'。所以在做题时注意这点。此外，还有个不同之处在于，虽然26对26取余为0，但是表达式中存在26（'Z'），这与我们常见的不同，比如二进制中就没有2（只有0， 1），十进制中没有10（0~9）。所以每次得到余数为0时，不仅要加入'Z'，还要在原数n中减去26（1~26都可以，毕竟后面还要进行取余运算）。

### C++
```
class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n)
        {
            int k = n % 26;
            if (k == 0)
            {
                ret = 'Z' + ret;
                n -= 26;
            }
            else{
                char prev = 'A'+k-1;
                ret = prev + ret;
            }
            n /= 26;
        }
        return ret;
    }
};
```

### Python
```
class Solution:
    def convertToTitle(self, n: int) -> str:
        ret = ""
        while n:
            print(n, n%26)
            k = n % 26
            if k == 0:
                ret = 'Z' + ret
                n -= 26
            else:
                ret = chr(k+64) + ret
            n //= 26
```

