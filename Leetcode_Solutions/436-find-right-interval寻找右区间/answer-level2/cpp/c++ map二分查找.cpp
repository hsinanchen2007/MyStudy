### 解题思路
c++的map封装了红黑树，是一种平衡的二叉搜索树，能够以logN的复杂度插入和查找。lower_bound()返回键值>=给定元素的第一个迭代器。由于题目中限定每个区间起点不同，故可以用区间起点做key， 区间在原数组的下标做value插入map。
时间复杂度：O(NlogN) 对每个区间，在map中二分查找右区间
空间复杂度：O(N) 使用map保存每个区间的起点和下标

### 代码

```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        int i = 0;
        for(auto v: intervals){
            m[v[0]] = i++;
        } 
        vector<int> ans;
        for(auto v: intervals){
            auto it = m.lower_bound(v[1]);
            if(it == m.end()) ans.emplace_back(-1);
            else ans.emplace_back((*it).second);
        }
        return ans;
    }
};
```