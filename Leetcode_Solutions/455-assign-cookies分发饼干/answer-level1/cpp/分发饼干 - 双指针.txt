### 解题思路
1. 对给出的`g`数组和`s`数组排序
2. 初始化`i`，`j`指针为`0`，分别用于扫描`g`和`s`，若有满足`g[i] <= s[j]`，则更新满足的数量`ans`
3. 直到`g`或者`s`被全部扫描完，返回`ans`

### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty() || g.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int n = g.size();
        int m = s.size();
        int ans = 0;
        while(i < n && j < m){
            if(g[i] <= s[j]){
                ans++;
                i ++;
                j ++;
            }
            else j ++;
        }
        return ans;
    }
};
```