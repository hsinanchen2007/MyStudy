### 解题思路
// 根据官方题解一：递归：
// 思路：假设输出子集开始为空，每一步都向子集添加新的整数，并生成新的子集
// eg： 123 为例
// 一开始，子集为空，这个添加上，作为一个子集
// 然后放入1，这样子集就有俩 []   [1]
// 再然后放入2， 原来的俩子集，再都加上2，形成新的子集： [] [1] [2] [1,2]
// 再放入3，进一步新的子集：[], [1], [2],[1,2], [3], [1,3],[2,3],[1,2,3]

### 代码

```cpp

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        output.push_back(vector<int>()); // 先放一个空集

        for(int num : nums) {
            vector<vector<int>> newEach;
            for(vector<int> ev : output) { // 将num追加到output中已有的每一个vector中
                ev.push_back(num);
                newEach.push_back(ev);  // 不能写作 output.push_back(ev);因为这样output就不断增加，死循环
            }

            for(vector<int> ev : newEach) { // 然后将新的子集也都添加到 output中，
                output.push_back(ev);
            }
        }
        return output;
    }
};
```