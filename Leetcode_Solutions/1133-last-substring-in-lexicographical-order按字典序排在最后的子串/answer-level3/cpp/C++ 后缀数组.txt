### 解题思路
首先本题只需要在所有后缀子串中找到字典序最大的那个。
后缀数组算法的思想是对于已经比较过的子串，利用之前的比较结果，不再重复比较。
参考资料：[https://www.***.org/suffix-array-set-2-a-nlognlogn-algorithm/](https://www.***.org/suffix-array-set-2-a-nlognlogn-algorithm/)

耗时还是不小，后面再找找原因。
![图片.png](https://pic.leetcode-cn.com/70b3f823a8629efa158246cccb1a91fb8fc45202f2c1f4f0f1712760515aece8-%E5%9B%BE%E7%89%87.png)

### 代码

```cpp
struct suffix {
    int index;
    int rank[2];
};

class Solution {
public:
    int LastSuffixArrayIdx(const string& txt) {
        int n = txt.size();
        struct suffix suffixes[n];

        for (int i = 0; i < n; ++i) {
            suffixes[i].index = i;
            suffixes[i].rank[0] = txt[i] - 'a';
            suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
        }

        auto compare = [](const struct suffix &a, const struct suffix &b) -> bool {
            return (a.rank[0] != b.rank[0]) ? (a.rank[0] < b.rank[0]) : (a.rank[1] < b.rank[1]);
        };
        sort(suffixes, suffixes + n, compare);

        vector<int> idxes(n);
        for (int i = 4; i < 2 * n; i *= 2) {
            int rank = 0;
            int prevRank = suffixes[0].rank[0];  // 保存一下原始的rank[0]
            suffixes[0].rank[0] = rank;
            idxes[suffixes[0].index] = 0;
            for (int j = 1; j < n; ++j) {
                if (suffixes[j].rank[0] == prevRank &&
                    suffixes[j].rank[1] == suffixes[j - 1].rank[1]) {
                    prevRank = suffixes[j].rank[0];
                    suffixes[j].rank[0] = rank;
                } else {
                    prevRank = suffixes[j].rank[0];
                    suffixes[j].rank[0] = ++rank;
                }
                idxes[suffixes[j].index] = j;
            }
            for (int j = 0; j < n; ++j) {
                int nextIndex = suffixes[j].index + (i / 2);
                suffixes[j].rank[1] = (nextIndex < n) ? suffixes[idxes[nextIndex]].rank[0] : -1;
            }
            sort(suffixes, suffixes + n, compare);
        }

        return suffixes[n - 1].index;
    }

    string lastSubstring(string s) {
        int idx = LastSuffixArrayIdx(s);
        return s.substr(idx);
    }
};
```