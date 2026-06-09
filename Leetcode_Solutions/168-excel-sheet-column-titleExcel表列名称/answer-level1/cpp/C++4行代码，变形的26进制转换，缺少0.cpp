因为缺少0位，所以我们把0对应A，.....， 25对应Z，让它变成标准的26进制
比方说52——AZ，若按标准26进制应该51——AZ，所以n--，使52变成51，然后取余。一直循环至n位0结束
```
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            int a = --n % 26;
            res += ('A'+a);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
