### 解题思路
昨天又忘记打卡，心痛

### 代码

```cpp
class Solution {
public:
    int f(int n, int m) {
        if (n == 1) {
            return 0; // 最后剩下的人在当前队列里的索引一定是0
        }
        int x = f(n - 1, m); // 如果 n - 1 个人中剩下的人的索引是x
        return (m + x) % n; // n个人中剩下的人的索引应该是 (m % n + x) % n = (m + x) % n
    }
    int lastRemaining(int n, int m) {
        //f(1,m)的索引一定是0
        int res = 0;
        // i 个人中留下的人在当前的队列中的索引是 res;
        for (int i = 2; i < n + 1 ; i++) {
            res = (m + res) % i;
        }
        return res;

    }
};
```