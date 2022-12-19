```
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> m;
        int res = 0, left = 0;
        for(int i=0; i<tree.size(); i++) {
            m[tree[i]]++;
            while(m.size() > 2) {
                if(--m[tree[left]] == 0) {
                    m.erase(tree[left]);
                }
                left++;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};
```
