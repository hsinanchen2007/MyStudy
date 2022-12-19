### 解题思路
计算组合边长和原始矩形边长和的关系

### 代码

```java []
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        long W1 = (long)Math.abs(rec1[0]-rec1[2]);
        long H1 = (long)Math.abs(rec1[1]-rec1[3]);

        long W2 = (long)Math.abs(rec2[0]-rec2[2]);
        long H2 = (long)Math.abs(rec2[1]-rec2[3]);

        long WW1 = (long)Math.abs(rec1[0]-rec2[2]);
        long HH1 = (long)Math.abs(rec1[1]-rec2[3]);

        long WW2 = (long)Math.abs(rec1[2]-rec2[0]);
        long HH2 = (long)Math.abs(rec1[3]-rec2[1]);

        return (W1+W2>Math.max(WW1, WW2) && H1+H2>Math.max(HH1, HH2));
    }
}
```
```python []
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, x2, y1, y2 = rec1
        x11, x22, y11, y22 = rec2

        W1, H1 = abs(x1-y1), abs(x2-y2)
        W2, H2 = abs(x11-y11), abs(x22-y22)

        WW1, HH1 = abs(x1-y11), abs(x2-y22)
        WW2, HH2 = abs(y1-x11), abs(y2-x22)

        return W1+W2>max(WW1, WW2) and H1+H2>max(HH1, HH2)
```
```c++ []
typedef long long ll;
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 使用边长和判定
        ll W1 = abs(rec1[0]-rec1[2]);
        ll H1 = abs(rec1[1]-rec1[3]);

        ll W2 = abs(rec2[0]-rec2[2]);
        ll H2 = abs(rec2[1]-rec2[3]);

        // 组合后
        ll WW1 = abs(rec1[0]-rec2[2]);
        ll HH1 = abs(rec1[1]-rec2[3]);

        ll WW2 = abs(rec1[2]-rec2[0]);
        ll HH2 = abs(rec1[3]-rec2[1]);

        return (W1+W2>max(WW1, WW2)) & (H1+H2>max(HH1, HH2));
    }
};
```