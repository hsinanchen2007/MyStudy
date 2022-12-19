奇数先手必败，无论怎么取，后手一定是偶数，后手只要取1让奇数回到先手，最终后手一定会得到2

反之，偶数先手取1，把奇数留给后手，必胜

代码：
```
class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 != 1;
    }
};
```
