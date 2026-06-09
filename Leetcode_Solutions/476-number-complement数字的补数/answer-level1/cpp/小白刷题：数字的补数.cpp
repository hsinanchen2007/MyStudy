类似进制转换，只是多了个位取反

代码：
```
class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int temp = 1;
        while (num) {
            ans = ans + temp * (1 - (num % 2));
            num = num >> 1;
            temp = temp << 1;
        }
        return ans;
    }
};
```
