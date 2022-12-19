### 解题思路
1.将胃口和饼干大小降序排列，优先满足胃口大的孩子也是最优解。

### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        for (int i = 0; i < g.size() && ans < s.size(); i++){
            if (g[i] <= s[ans]){
                ans++;
            }
        }   
        return ans;
    }
};
```