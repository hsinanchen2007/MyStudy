
## 思路

扫描线 + 大顶堆

有序集合保存扫描线，扫描线由建筑物进入和离开的位置构成

扫描过程：

1. 出堆操作；堆顶建筑物是否在扫描线左边；是->出堆；
2. 入堆操作；扫描线是否扫到了需要入堆的建筑物；如果是，进行入堆；用下标i记录我们已经扫到了第几个建筑物；
3. 记录结果集；三种情况：结果集为空（开始状态）；堆为空（没有建筑物）；当前堆顶跟结果集最后一个不一致（有出堆或入堆操作，造成天际线高度改变），加入结果集；

## 代码

cpp

```cpp
struct Node {
    int start, end, high;
    Node(int _s, int _e, int _h) : start(_s), end(_e), high(_h) {};
    bool operator<(const Node &other) const {
        return this->high < other.high;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        // 初始化结果集
        vector<vector<int>> skylines;
        // 所有进入建筑物和离开建筑物的位置，进行扫描，记录扫描线的位置
        set<int> scanner;
        for (int i = 0; i < buildings.size(); i++) {
            scanner.insert(buildings[i][0]);
            scanner.insert(buildings[i][1]);
        }

        // 用大顶堆保存建筑物的信息{start, end, high} （按照high排序）
        priority_queue<Node> heap;
        int i = 0; // i 表示当前建筑物下标
        for (auto it = scanner.begin(); it != scanner.end(); it++) {
            int line = *it;
            // 判断扫描线是否已经到达当前堆顶的建筑物离开的位置；如果是，进行出堆操作；循环
            while (!heap.empty() && heap.top().end <= line) { // 出堆
                heap.pop();
            }
            // 扫描到建筑物进入，进行入堆操作
            while (i < buildings.size() &&buildings[i][0] <= line ) {
                heap.push({buildings[i][0], buildings[i][1], buildings[i][2]});
                i++;
            }

            // 记录结果集
            if (skylines.size() == 0) { // 初始状态
                skylines.push_back({line, heap.top().high});
            } else if (heap.size() == 0 && skylines[skylines.size() - 1][1] != 0) { // 堆为空
                skylines.push_back({line, 0});
            } else if (skylines[skylines.size() - 1][1] != heap.top().high) { // 当前堆顶跟结果集最后一个高度不一致；
                skylines.push_back({line, heap.top().high});
            }
        }
        return skylines;
    }
};
```
