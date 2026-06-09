### 解题思路
![QQ截图20200326170706.png](https://pic.leetcode-cn.com/f0a29831972a6c22c0889204d7e77906686cc757ba0ed16bf7e06a1ed8d23b3d-QQ%E6%88%AA%E5%9B%BE20200326170706.png)
此处撰写解题思路

算法步骤：
1. 预处理，start中存x小的，x相同时，存y小的;
2. 斜率不存在： a. 两个都不存在 b. 一个存在
3. 斜率存在：a. 斜率相等 b. 斜率不相等

### 代码

```cpp
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        // 0. 预处理，按x值进行排序, x相同时按y排序
        if (start1[0] > end1[0] || (start1[0] == end1[0] && start1[1] > end1[1])) {
            auto p = start1;
            start1 = end1, end1 = p;
        }
        
        if (start2[0] > end2[0] || (start2[0] == end2[0] && start2[1] > end2[1])) {
            auto p = start2;
            start2 = end2, end2 = p;
        }
        
        // 1. 斜率不存在: x = a;
        if (start1[0] == end1[0] || start2[0] == end2[0]) {
            if (start1[0] == end1[0] && start2[0] == end2[0]) { // 1.1. 两个都不存在
                if (start1[0] != start2[0]) return {};  // 1.1.1 斜率不相等，无解
                else { // 1.1.2 斜率相等
                    // 判断line1, line2，谁的起始坐标更小
                    if (start1[1] <= start2[1]) {
                        if (end1[1] >= start2[1]) return {(double)start2[0], (double)start2[1]}; // 交叉有解，较大的其实坐标即最小值
                        return {};
                    } else {
                        if (end2[1] >= start1[1]) return {(double)start1[0], (double)start1[1]};
                        return {};
                    }
                }
            } else if (start1[0] == end1[0]) { // 1.2 line1斜率不存在
                vector<double> line2 = getLine(start2, end2);
                double x = start1[0], y = line2[0] * x + line2[1]; // 求交点
                if (y >= start1[1] && y <= end1[1] && y >= start2[1] && y <= end2[1]) return {x, y}; 
                return {};
            } else { // 1.3 line2斜率不存在
                vector<double> line1 = getLine(start1, end1);
                double x = start2[0], y = line1[0] * x + line1[1];
                if (y >= start1[1] && y <= end1[1] && y >= start2[1] && y <= end2[1]) return {x, y};
                return {};
            }            
        } 
        
        // 2. 一般情况
        vector<double> line1 = getLine(start1, end1), line2 = getLine(start2, end2); // 数学公式，获取斜率和截距
        
        // 2.1 斜率相等
        if (line1[0] == line2[0]) {
            if (line1[1] == line2[1]) {  // 2.1.1 同一条直线
                if (start1[0] <= start2[0]) { // 判断谁的横坐标最小
                    if (end1[0] >= start2[0]) return {(double)start2[0], (double)start2[1]};
                    return {};
                } else {
                    if (end2[0] >= start1[0]) return {(double)start1[0], (double)start1[1]};
                    return {};
                }
            }
            return {};
        }
        
        // 2.2 斜率不相等
        double x = (line2[1] - line1[1]) / (line1[0] - line2[0]), y = line1[0] * x + line1[1]; // 求交点
        if (x >= start1[0] && x <= end1[0] && x >= start2[0] && x <= end2[0]) return {x, y}; 
        return {};
    }
    
    vector<double> getLine(vector<int> st, vector<int> ed) {
        double k = (double) (st[1] - ed[1]) / (st[0] - ed[0]), b = st[1] - k * (double) st[0];
        return {k, b};
    }
};
```