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
# 过气小公主求关注
![image.png](https://pic.leetcode-cn.com/d6ea818117c32ad9445faee75e871f425be028b3ca157b5238ce98b46b0116d0-image.png)

![](https://pic.leetcode-cn.com/f18e68ed2306a147b615407e0b0260900672940df4a2fd9a7f7dc9b91e23e55e.jpg)
