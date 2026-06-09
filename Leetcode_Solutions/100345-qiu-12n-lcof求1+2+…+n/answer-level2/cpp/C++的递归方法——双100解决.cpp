#### 既然不能if，while等关键字，采用逻辑与的短路特性实现递归终止
```
class Solution {
public:
    int sumNums(int n) {
        int ans = n;
        ans && (ans += sumNums(n - 1)); // 用逻辑与的短路特性实现递归终止
        return ans;
    }
};
```