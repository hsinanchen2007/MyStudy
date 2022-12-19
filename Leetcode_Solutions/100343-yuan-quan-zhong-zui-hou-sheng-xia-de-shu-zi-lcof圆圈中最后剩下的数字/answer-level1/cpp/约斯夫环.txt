### 解题思路
递归思想1------0
2------0+3%2==1
```
代码块
```
.
.
.

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
if (n == 1)
		return 0;
	return(lastRemaining(n - 1, m) + m) % n;
    }
};
```