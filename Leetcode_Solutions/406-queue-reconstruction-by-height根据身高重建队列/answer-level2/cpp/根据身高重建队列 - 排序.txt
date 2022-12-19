### 解题思路
1. 对于给定的整数对`(h,k)`按照身高`h`降序排列，若出现身高相同的，按照人数`k`升序排列
2. 对`1.`排序后数组进行插入排序（按照`k`插入，非严格插入排序）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& lp, vector<int>& rp){
            return lp[0] == rp[0] ? lp[1] < rp[1] : lp[0] > rp[0];});
        int len = people.size();
        list<vector<int>> tmp;
        for(int i = 0; i < len; ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
```