### 解题思路
看作图的BFS即可，用set记录已经出现过的情况（也可以用vector<vector<bool>> visited(x, vector<bool>(y, false))）。
1. 两个桶不可能同时有水且不满, 操作的结果都至少有一个桶是空的或者满的
2. 把一个不满的桶倒满没有意义
3. 把一个不满的桶倒空没有意义

### 代码
```cpp
bool canMeasureWater(int x, int y, int z) {
    if(z == 0) return true;
    if(z < 0 || x + y < z) return false;
    if(x == 0) return y == z;   // 还有 "0 2 1" 这样的测试用例
    if(y == 0) return x == z;
    set<pair<int, int>> st;
    st.emplace(0, 0);
    queue<pair<int, int>> q;
    q.emplace(x, y);
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        const int cx = t.first, cy = t.second;
        if(cx == z || cy == z || cx + cy == z) return true;
        if(st.find(t) != st.end()) continue;    // 已经遍历过
        st.emplace(cx, cy);
        if(cx != 0) {   // A不空，A倒B
            if(cx + cy > y) q.emplace(cx + cy - y, y);
            else            q.emplace(0, cx + cy);
        }
        if(cx == x)  q.emplace(0, cy);  // A满，A倒空
        if(cx == 0)  q.emplace(x, cy);  // A空，A倒满
        if(cy != 0) {   // B不空，B倒A
            if(cy + cx > x) q.emplace(x, cy + cx - x);
            else            q.emplace(cx + cy, 0);
        }
        if(cy == y) q.emplace(cx, 0);   // B满，B倒空
        if(cy == 0) q.emplace(cx, y);   // B空，B倒满
    }
    return false;
}
```