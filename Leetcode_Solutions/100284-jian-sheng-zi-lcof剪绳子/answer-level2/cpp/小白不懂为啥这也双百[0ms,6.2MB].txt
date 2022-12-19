### 解题思路
思考的还不够好，导致代码复杂了
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {

        if (n < 1)
            return -1;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        //存储累乘
        vector<int> s;
        //要么全是一个值，要么只有一个值不同，不同值大1或者小1
        for (int i = 2; i <= n / 2; ++i) {
            int up = i + 1;
            int down = i - 1;
            for (int j = 2; j <= n / 2; ++j) {
                //判断是一种情况，将符合情况的都存入s
                if ((i * j) == n)
                    s.push_back(max(pow(double(i), double(j)), pow(double(j), double(i))));
                if ((i * (j - 1) + up) == n)
                    s.push_back(max(pow(double(i), double(j - 1)) * up, pow(double(j - 1), double(i)) * up));
                if ((i * (j - 1) + down) == n)
                    s.push_back(max(pow(double(i), double(j - 1)) * down, pow(double(j - 1), double(i)) * down));

            }
        }
        //输出最大值
        return *max_element(s.begin(), s.end());
    }
};

```