### 解题思路
此题与斐波那契数列相同，思路一递归法简单但是超时，思路二是使用数组存储，取第n个数。
### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
    std::vector<int> vec = {1, 1};

    for(int i = 2; i <= n; i++){
        vec.push_back((vec[i-2] + vec[i-1])%1000000007);
    }

    return vec[n];
    }
};
```