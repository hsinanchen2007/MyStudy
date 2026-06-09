### 解题思路
1. 用unordered_map保存所有region的parent
2. 从region1和region2开始网上查找，并保存找到的父区域到Set
3. 如果region1新增的父区域，在region2的父区域Set里，则说明找到了，反之亦然。

![图片.png](https://pic.leetcode-cn.com/2e71289320ae87cc57a52522f4ee58872d0a5ae9a355282c018c816cca27bd47-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;  // 保存每个区域的父区域
        for (vector<string> reg : regions) {
            for (int i = 1; i < reg.size(); ++i) {
                parent[reg[i]] = reg[0];
            }
        }
        set<string> pSet1;     // 保存region1的父区域集合
        pSet1.insert(region1);
        set<string> pSet2;     // 保存region2的父区域集合
        pSet2.insert(region2);
        bool p1isTop = false;  // 表示是否已经上溯到顶
        bool p2isTop = false;
        do {
            if (!p1isTop) {
                if (parent.find(region1) != parent.end()) {
                    region1 = parent[region1];
                    if (pSet2.find(region1) != pSet2.end()) {  // 如果region1新增的父区域在region2的父区域集合里，则说明已经找到!
                        return region1;
                    } else {
                        pSet1.insert(region1);  // 更新region1的父区域列表
                    }
                } else {
                    p1isTop = true;
                }
            }
            if (!p2isTop) {
                if (parent.find(region2) != parent.end()) {
                    region2 = parent[region2];
                    if (pSet1.find(region2) != pSet1.end()) {  // 如果region2新增的父区域在region1的父区域集合里，则说明已经找到!
                        return region2;
                    } else {
                        pSet2.insert(region2);  // 更新region2的父区域列表
                    }
                } else {
                    p2isTop = true;
                }
            }
        } while (!p1isTop || !p2isTop);  // 直到两个都回溯到顶才结束循环

        // 没有找到公共区域，不可能走到这里。
        return string();
    }
};
```