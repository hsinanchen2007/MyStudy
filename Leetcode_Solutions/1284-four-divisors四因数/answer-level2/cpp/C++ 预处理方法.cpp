## 5178. 四因数
先思考最直接的方法：
 1. 枚举每个数的因子。设最大值为$m$，则时间复杂度为$O(n*m)$。
 2. 检查每个数因子的个数，并累加符合要求的因子。时间复杂度为$O(n)$。
 
因为 n，m 都较大，直接按上述方法暴力肯定是要超时的。那么来思考下如何优化。
观察发现，耗时主要集中在第一步，那么就来搞一搞它！
我们现在时先枚举数字，再枚举它的因子，那么能不能**反过来**呢？先枚举因子，然后枚举有可能被该因子整除的数字。好像是可行的，不过别慌，先让我们来估计下时间复杂度：
1. 枚举因子。设最大因子为$m$，则时间复杂度为$O(m)$。
2. 对于每个因子 x 。枚举可以被其整除的数字。设最大的数字取值不超过 n，则该步骤的时间复杂度为 $O(n/x)$。

总结一下，上述算法的时间复杂度为 $O(m*\sqrt n)$。已经足够解决题目给出的数据了。

```cpp
bool flag = false;
unordered_map<int, unordered_set<int>> eleDict;
void init() {
    for(int i = 1; i <= 100000; i++) {
        for(int j = i; j <= 100000; j += i) {
            eleDict[j].insert(i);
        }
    }
}
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        if(flag == false) {
            init();
            flag = true;
        }
        int sum = 0;
        for(auto it = nums.cbegin(); it != nums.cend(); ++it) {
            const unordered_set<int> &eles = eleDict[*it];
            if(eles.size() == 4) {
                for(auto pit = eles.cbegin(); pit != eles.cend(); pit++) {
                    sum += *pit;
                }
            }
        }
        return sum;
    }
};
```
## 5366. 检查网格中是否存在有效路径
典型的图的优先搜索问题。比较考验处理细节的能力。
可以借助 std::queue 来几率待搜索的点，借助 std::unordered_set 记录已访问的点。每次从 queue 的队首取出待搜索节点，记为  f，然后枚举 f 周围的四个节点，根据题目给出的 street-type 判断是否可达。

```cpp
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};
class Solution {
public:
    bool isAccess(int cur, int next, int dir) {
        if (dir == 0){
            if((cur == 2 || cur == 5 || cur == 6) && (next == 2 || next == 3 || next == 4)) {
                return true;
            }
        }
        if (dir == 1){
            if((cur == 1 || cur == 4 || cur == 6) && (next == 1 || next == 3 || next == 5)) {
                return true;
            }
        }
        if (dir == 2){
            if((cur == 2 || cur == 3 || cur == 4) && (next == 2 || next == 5 || next == 6)) {
                return true;
            }
        }
        if (dir == 3){
            if((cur == 1 || cur == 3 || cur == 5) && (next == 1 || next == 4 || next == 6)) {
                return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        set<pair<int,int>> mark;
        mark.insert(make_pair(0,0));
        while(q.empty() == false) {
            auto f = q.front(); q.pop();
            if(f.first == grid.size()-1 && f.second == grid[0].size()-1) {
                return true;
            }
            for(int i = 0; i < 4; i++) {
                auto next = make_pair(f.first + dx[i], f.second + dy[i]);
                if(mark.find(next) != mark.end()) {
                    continue;
                }
                if(next.first < 0 || next.first >= grid.size() || next.second < 0 || next.second >= grid[0].size()) {
                    continue;
                }
                if(false == isAccess(grid[f.first][f.second], grid[next.first][next.second], i)) {
                    continue;
                }
                q.push(next);
                mark.insert(next);
            }
        }
        return false;
    }
};
```
## 5367. 最长快乐前缀
可以使用 hash 算法，O(n)搞定该问题。

**首先假设有一个足够大的数据类型可以装下我们所需要的数字。** 后面会优化掉对该假设的依赖~

对于长度为 i 的前缀，我们可以计算其hash值，计算公式如下：
$prefix(i) = \sum^{i-1}_{j =0}*(s[i]-'a')*salt^{j}$

对于长度为 i 的后缀，我们可以计算其hash值，设字符串长度为 n，计算公式如下：
$suffix(i) = \sum_{j=0}^{i-1}(s[n-i+j]-'a')*salt^{j}$

salt 是一个随机数，但最好是一个大的质数。
分析上述两个公式会发现，如果长度为 i 的前缀和后缀相等，那么必然有 prefix(i) == suffix(i)。而且在满足**前述假设**的前提下，不相等的前缀和后缀必然有 prefix(i) ≠ suffix(i)。

但是可惜的是，并没有在大多数编程语言中，并不存在这样的数据类型。从而导致了hash值冲突的问题，即不相等的前缀和后缀其hash值也有可能相同。那么如何解决该问题呢？

借鉴于通用的解决hash冲突的办法，我们可以增加 salt 的个数，以降低冲突的概率。当长度为 i 的前缀和后缀对于所有salt都相等时，我们才认为其真正的相等。

```cpp
enum { MAXN = 3 };
uint64_t salt[MAXN] = {1000007, 100000007, 1000000007};
class Solution {
public:
    vector<uint64_t> feature[2][MAXN];
    string longestPrefix(string s) {
        for(int i = 0; i < MAXN; i++) {
            feature[0][i].resize(s.size());
            feature[1][i].resize(s.size());
            for(uint64_t mul = 1, k = 0, n = s.size(); k < n; k++, mul *= salt[i]) {
                if(k == 0) {
                    feature[0][i][k] = s[0]-'a';
                } else {
                    feature[0][i][k] = feature[0][i][k-1] + mul*(s[k]-'a');
                }
            }
            for(int k = s.size()-1; k >= 0; k--) {
                if(k == s.size()-1) {
                    feature[1][i][k] = s[k]-'a';
                } else {
                    feature[1][i][k] = (s[k]-'a') + feature[1][i][k+1]*salt[i];
                }
            }
        }
        for(int i = s.size()-2; i >= 0; i--) {
            if(feature[0][0][i] == feature[1][0][s.size()-i-1]
              && feature[0][1][i] == feature[1][1][s.size()-i-1]
              && feature[0][2][i] == feature[1][2][s.size()-i-1]) {
                return s.substr(0, i+1);
            }
        }
        return "";
    }
};
```
# 扫码关注 快乐加倍
![image.png](https://pic.leetcode-cn.com/81b81620ed28d8c4db031072c1d238c88f57f65ec1d66c04865e756d428d80df-image.png)

![](https://pic.leetcode-cn.com/2d18292854d93640f157c04b3896d7adfd2784f130c3b746174279d9ab2cd8d0.jpg)
