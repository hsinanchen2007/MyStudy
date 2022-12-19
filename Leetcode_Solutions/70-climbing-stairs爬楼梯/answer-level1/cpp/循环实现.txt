### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int a[200];
    int climbStairs(int n) {
        a[0] = a[1] = 1;
        for(int i=2;i<=n;i++){
            a[i] = a[i-1]+a[i-2];
        }
        return a[n];
    }
};
```