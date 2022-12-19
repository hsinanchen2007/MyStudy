### 解题思路
1.对需求因子数组g与糖果大小数组s进行从小到大的排序。
2.按照从小到大的顺序使用各糖果尝试是否可满足某个孩子，每个糖果只尝试1次；若尝试成功，则换下一个孩子尝试；直到发现没更多的孩子或者没更多的糖果，循环结束。

### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0;
        while (child<g.size()&&cookie<s.size()) {
            if(g[child]<=s[cookie]) {
                child++;
            }
            cookie++;
        }
        return child;
        
    }
};
```