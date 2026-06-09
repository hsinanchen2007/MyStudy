### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i=2; i<=n; ++i){
            ans = (ans + m) % i;
        }
        return ans;
    }
};
```