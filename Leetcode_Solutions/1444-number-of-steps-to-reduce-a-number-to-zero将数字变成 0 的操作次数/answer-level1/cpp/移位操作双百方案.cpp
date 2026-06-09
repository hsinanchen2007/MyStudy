#### 双百方案：
```
class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while (num) {
            if (num & 1) { // 除了1以外的奇数都要求两次操作
                cnt += 2;
            }
            else { // 偶数除一次2，操作一次
                cnt++;
            }
            num >>= 1;
        }
        return cnt - 1;
    }
};
```