### 解题思路
注意取余操作 存放到数组之前就取余


### 代码

```cpp
class Solution {
public:

    int fib(int n) {

        vector<int> v(100 + 1);
        v.at(0) = 0;
        v.at(1) = 1;

        for (int i = 2; i <= n; ++i)
        {
            v.at(i) = (v.at(i - 1) + v.at(i - 2)) % 1000000007;
        }

        return v.at(n);
    }
};
```