### 解题思路
  怎么说呢，我的理解就是。从最小的开始找，找到的位置就是在后面一次补齐的位置。因为每次操作过后，剩下的始终是n-1。

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int s = 0;
        for(int i = 2 ; i <= n ; i++){
            s = (s + m) % i;
        }
        return s;
    }
};
```