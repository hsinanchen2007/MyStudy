### 解题思路

首先得承认下，自己真的很菜鸡，智商不够

思路一：
1、第一想法是双指针+滑窗求出所有字符串，明显自己知道肯定会超时，还是进行了尝试
2、然后再想了下，可以优化，通过遍历字符串的长度存在的可能，然后构造第一个字符串，并进行HASH存储
3、下次字符串加入的时候通过增加和减少HASH表中对应字符的个数来进行重新统计HASH表
4、曾经想过用HASH的出入来决定是不是要累加上一次的值，不过用例没有通过，时间限制，没继续调试了
很明显，超时
39/63

思路二：
1、以每个字符的存在生命周期来计算，而不是字符串
2、遍历一遍字符串，在每个字符对应位置往前往后搜索，直到同样的字符出现，那么包含这个字符的所有字符串个数可以知道，也就是当前这个位置的字符能产生的贡献值
3、搜索到尾部结束，时间复杂度应该是O(K*n)

28ms 9.5M
--- wangtao HW-2020/3/7

### 代码 AC

```cpp
class Solution {
public:
    int uniqueLetterString(string S) {
        long sum = 0;

        long mod = 1000000007;
        int i, j, k;
        for (i = 0; i < S.size(); i++) {
            for (j = i - 1; j > -1 && S[j] != S[i]; j--) {}
            for (k = i + 1; k < S.size() && S[k] != S[i]; k++) {}
            sum += (i - j) * (k - i) % mod;
        }
        return sum;
    }
};
```
### 代码 超时
```cpp
class Solution {
public:
    int mod = 1000000007;

    int uniquestringnum(map<char, int>& hash)
    {
        int ans = 0;
        for (auto c : hash) {
            if (c.second == 1) {
                ans = (ans + 1) % mod;
            }
        }
        return ans;
    }

    int uniqueLetterString(string s) {
        int n = s.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            int i = 0;
            // 每轮维持一个HASH列表，下次计算前看下是否需要
            map<char, int> hash;
            int lastindex = i;
            while (i <= n - k) {
                string tmpstr = s.substr(i, k);
                if (i == 0) {
                    for (auto c : tmpstr) {
                        hash[c]++;
                    }
                } else {
                    hash[s[lastindex]]--;
                    hash[s[i + k - 1]]++;
                }
                ans = (ans + uniquestringnum(hash)) % mod;
                lastindex = i;
                i++;
            }
        }
        return ans;
    }
};

```
