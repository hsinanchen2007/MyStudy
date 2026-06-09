经典的鸡兔同笼问题，假设大汉堡x个，小汉堡y个，可列方程组

4x + 2y = ts

x + y = bs

对应求解即可

```c++
class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
        if (ts - 2 * cs < 0) return {};
        if ((ts - 2 * cs) % 2) return {};
        int x = (ts - 2 * cs) / 2, y = cs - x;
        if (y < 0) return {};
        return {x, y};
    }
};
```

