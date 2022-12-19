### 解题思路
![1.png](https://pic.leetcode-cn.com/e3046d2c920a378c968be47ef0a4bbd3ebc1693a5a1a9d5c1b405f94cf62426a-1.png)

### 代码
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (auto& num : A)
            num = pow(num, 2);
        sort(A.begin(), A.end());
        return A;
    }
};
```