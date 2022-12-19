

### 解题思路
此处撰写解题思路
map缩点+并查集很经典
把第i-1 和 i连起来
i和i+1 连起来记录一下每个集合的个数。最大的就是最长链。
### 代码

```cpp
class Solution {
public:
    vector<int> fa, sum;
    void init() {
        for (int i = 0; i < fa.size(); ++i) 
            fa[i] = i, sum[i] = 1;
    }
    int Find(int &x) {
        return x == fa[x] ? x : fa[x] = Find(fa[x]); 
    }
    bool Uion(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx == fy)
            return false;
        sum[fx] += sum[fy];
        fa[fy] = fx;
        return true;
    }
    // int max(initializer_list<int> li) {
    //     int &a = *li.begin();
    //     for (auto &i : li)
    //         a = a>i?a:i;
    //     return a;
    // }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int>ma;
        fa = sum = vector<int>(nums.size()+1);
        init();
        int tot = 0;
        for (auto &i : nums) {
            if (ma.find(i) != ma.end()) continue;
            ma[i] = tot++;
            if (ma.find(i-1) != ma.end())
                Uion(ma[i-1], ma[i]);
            if (ma.find(i+1) != ma.end())
                Uion(ma[i], ma[i+1]);
        }
        int x = sum[Find(ma[nums[0]])];
        for (auto &i : nums)
            x = max(x, sum[ma[i]]);
        return x;
    }
};
```