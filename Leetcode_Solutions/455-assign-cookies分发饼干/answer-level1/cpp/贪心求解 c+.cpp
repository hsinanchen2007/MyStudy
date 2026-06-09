### 解题思路
1.先对两数组进行排序
2.依次遍历s,满足则加一，贪心求解
### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       // if(g.size() == NULL || s.size() == NULL) return 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0 ;
        while(cookie < s.size() && child < g.size()){
            if(s[cookie] >= g[child]){
                child++;
            }
            cookie++;
        }
        return child;

    }
};
```