```
class Solution {
public:
    bool divisorGame(int N) {
        if( N%2 == 0 )
            return 1;
        else
            return 0;
    }
};
```
实际上这种解法像是投机取巧，在从小到大逐渐测试的时候发现偶数时都可以取胜，奇数都会失败，因此直接对N取余即可。