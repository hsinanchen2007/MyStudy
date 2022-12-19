对于这种两两互相关系的情况通常使用并查集。并查集的father表示当前元素是father的倍数。在查找father时可以压缩路径，降低之后的查询复杂度。

```c++
struct Union{
    Union* father;
    double times;
    Union(): father(NULL), times(1.0){}
    pair<Union*, double> getRoot(){
        if(!father)
            return make_pair(this, 1);
        auto root = father->getRoot();
        father = root.first;
        times *= root.second;
        return make_pair(father, times);
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, Union*> ptrs;
        vector<double> ans;
        for(int i = 0; i < values.size(); i++){
            string s1 = equations[i][0], s2 = equations[i][1];
            double val = values[i];
            if(!ptrs.count(s1))
                ptrs[s1] = new Union();
            if(!ptrs.count(s2))
                ptrs[s2] = new Union();
            auto p1 = ptrs[s1], p2 = ptrs[s2];
            auto root1 = p1->getRoot(), root2 = p2->getRoot();
            root1.first->father = root2.first;
            root1.first->times = val * root2.second / root1.second;
        }

        for(auto i: queries){
            auto p1 = ptrs[i[0]], p2 = ptrs[i[1]];
            if(!p1 || !p2){
                ans.push_back(-1);
                continue;
            }
            auto root1 = p1->getRoot(), root2 = p2->getRoot();
            if(root1.first != root2.first)
                ans.push_back(-1);
            else
                ans.push_back(root1.second / root2.second);
        }
        return ans;
    }
};
```