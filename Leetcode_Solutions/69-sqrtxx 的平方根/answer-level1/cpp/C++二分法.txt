### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) {
            return x;
        }
        int l = 1;
        int r = x/2;
        while(l<=r) {
            int m = l + (r-l)/2;
            int sqrt = x / m;
            if(m == sqrt) {
                return m;
            }
            else if(m > sqrt) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
};
```