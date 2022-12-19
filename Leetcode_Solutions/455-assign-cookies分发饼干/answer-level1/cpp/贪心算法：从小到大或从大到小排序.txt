**贪心思想：**
从小到大排序，饼干小了只能是小了，丢弃，换更大的饼干尝试喂当前最小的孩子，kid不加，cookie++；
从大到小排序，孩子喂不饱只能喂不饱，换下一个，拿当前最大的饼干喂后面更小的孩子，cookie不变，kid++。

**sort函数：**
sort(g.begin(), g.end());//（默认）升序
sort(g.begin(), g.end(), greater<int>());//降序


#升序
```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int kid=0,cookie=0;
        while(kid < g.size() && cookie < s.size())
        {
            if(s[cookie] >= g[kid])
            {
                kid ++;
            }
            cookie ++;
        }
        return kid;
    }
};
```

#降序
```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());//降序
        sort(s.begin(), s.end(), greater<int>());
        int kid=0,cookie=0;
        while(kid < g.size() && cookie < s.size())
        {
            if(s[cookie] >= g[kid])
            {
                cookie ++;
            }
            kid ++;
        }
        return cookie;
    }
};
```



\\嗐，不会DP