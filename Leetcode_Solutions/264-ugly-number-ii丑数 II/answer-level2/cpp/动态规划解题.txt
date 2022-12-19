### 解题思路
避雷：最后判断的时候一定一定不能用else if！因为2*3和3*2这种等价关系！！！

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        int as[n+1];
        as[1] = 1;
        int ptr2 = 1;
        int ptr3 = 1;
        int ptr5 = 1;
        for (int i=2; i<=n; i++) {
            int a = as[ptr2]*2;
            int b = as[ptr3]*3;
            int c = as[ptr5]*5;
            as[i] = min(min(a, b), c);
            if (as[i] == a) {
                ptr2++;
            }
            if (as[i] == b) {
                ptr3++;
            }
            if (as[i] == c) {
                ptr5++;
            }
        }
        return as[n];
    }
};
```