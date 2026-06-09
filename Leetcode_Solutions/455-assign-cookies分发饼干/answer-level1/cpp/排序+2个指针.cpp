```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());//bitsuit
        int i,j;
        i=j=0;
        while (i<s.size()&&j<g.size()) {
            if(s[i]>=g[j]){
                j++;i++;ans++;
            }else i++;
        }
        return ans;
    }
};
```
**和 122 买卖股票的最佳时机 II有点像  **