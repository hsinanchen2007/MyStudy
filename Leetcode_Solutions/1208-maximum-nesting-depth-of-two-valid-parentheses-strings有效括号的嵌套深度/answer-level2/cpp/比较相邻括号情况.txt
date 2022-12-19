### 解题思路
遇到"()",")(" 可以放到同一组
遇到"((","))" 不可以放到同一组（xor 1 取反即可）

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<seq.size();++i){
            if(seq[i]==seq[i-1]) ans.push_back(ans.back()^1);
            else ans.push_back(ans.back());
        }
        return ans;
    }
};
```