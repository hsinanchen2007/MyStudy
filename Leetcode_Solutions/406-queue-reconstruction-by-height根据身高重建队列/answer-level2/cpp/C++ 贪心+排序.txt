### 解题思路

思路很简单：**按照[h,k]中h从大排序，如果h相同按照k从小到大排序**。

可以使用**list容器**方便进行插入工作，减小频繁的拷贝动作。


**代码：**
```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
        *  1. 首先考虑身高相同的情况: 例如 [7,0] 和 [7,1], [7,0]一定在[7,1]前面
        *  2. 然后接着考虑身高不同的情况, 身高低的相对于身高高的人来说, 是看不见的, 不影响k值
        *  3. 所以可以按照 [h,k] h大小排序, h相同按照k的大小排序
        *  4. [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]  --- >->->
        *     [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
        *  5. 按照 [h,k]中k的位置在容器中插入: 
        *     5.1 -> [7,0], [7,1]
        *     5.2 -> [7,0], [6,1], [7,1]
        *     5.3 -> [5,0], [7,0], [6,1], [7,1]
        *     5.4 -> [5,0], [7,0], [5,2], [6,1], [7,1]
        *     5.5 -> [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
        */
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
        };
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> sort_list;
        for (auto item : people) {
            auto iter = sort_list.begin();
            advance(iter, item[1]);
            sort_list.insert(iter, item);
        }
        vector<vector<int>> ret(sort_list.begin(), sort_list.end());
        return ret;
    }
};
```