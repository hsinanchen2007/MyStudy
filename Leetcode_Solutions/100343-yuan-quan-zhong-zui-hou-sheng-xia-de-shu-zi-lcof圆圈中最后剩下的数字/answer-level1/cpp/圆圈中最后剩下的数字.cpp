### 解题思路
数学，递归

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int last = 0;
        for(int i=2;i<=n;i++){
            last = (last + m) % i;
        }

        return last;
    }
};
```