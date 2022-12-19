### 解题思路
1. 两个栈stx和sty，其中stx存储位置，sty存储高度
2. 维护sty栈递减，某个i入栈时,先要pop出sty栈中小于height[i]的所有元素
3. 出栈时计算出栈的高度和height[i]之间可构成的面积(i-stx.top()-1)*(sty.top()-dlt);其中dlt是前一个出栈的高度。
4. 出栈操作结束后，如果当前栈为空，直接将i和height[i]入栈；
5. 如果当前栈不为空则计算(i-stx.top()-1) * (height[i]-dlt)加到result中。


一开始以为是要求连通最大量，感觉要比总量难一些。
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (!height.size()) return 0;
        stack<int> stx;
        stack<int> sty;
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            int dlt = 0;
            while (!sty.empty() && height[i] >= sty.top()) {
                int x = stx.top(), y = sty.top();
                stx.pop();
                sty.pop();
                result += (i-x-1) * (y-dlt);
                dlt = y;
            }
            if (!sty.empty()) result += (i-stx.top()-1) * (height[i]-dlt);
            stx.push(i);
            sty.push(height[i]);
        }
        return result;
    }
};
```