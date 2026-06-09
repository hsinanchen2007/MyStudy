### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
        if (A == 1) return B;
        if (B == 1) return A;
        return multip(A, B, 1, 0);
    }
    int multip(int A, int B, long C, int cnt) {
        if (B == C) {
            return A << cnt;
        }

        long next = C << 1;
        if (B > C && B < next) {
            long tmp = 0;
            if (B - C > next - B) {
                tmp = A << (cnt + 1);
                for (int i = 0; i < next - B; ++i) {
                    tmp -= A;
                }
            } else {
                tmp = A << cnt;
                for (int i = 0; i < B - C; ++i) {
                    tmp += A;
                }
            }
            return tmp;
        }

        return multip(A, B, next, cnt + 1);
    }
};
```