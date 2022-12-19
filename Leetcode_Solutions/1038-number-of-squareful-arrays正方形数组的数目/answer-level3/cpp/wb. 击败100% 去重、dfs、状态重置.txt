### 解题思路
1. 去重
2. dfs 用map记录不重复元素出现的个数，并作为是否访问标记
3. 单条路径遍历结束或遇到断路，状态重置；
4. 访问标记紧随stack pop之后，path push_back亦是如此
5. 初始化时，用map<int, set<int>>存储所有不重复数的有效邻居集合
### 代码

```cpp
class Solution {
public:
    bool Help(int a, int b) {
        int x = sqrt(a + b);
        for (int x2 : {pow(x, 2), pow(x + 1, 2)}) {
            if (x2 == a + b) {
                return true;
            }
        }
        return false;
    }
    int numSquarefulPerms(vector<int>& A) {
        int len = A.size();
        unordered_map<int, int> mCnt;
        for (int i = 0; i < len; i++) {
            mCnt[A[i]]++;
        }
        set<int> nums(A.begin(), A.end());
        vector<int> b(nums.begin(), nums.end());
        unordered_map<int, set<int>> m;
        for (int i = 0; i < b.size(); i++) {
            for (int j = i; j < b.size(); j++) {
                if (Help(b[i], b[j]) == true) {
                    m[b[i]].insert(b[j]);
                    m[b[j]].insert(b[i]);
                }
            }
        }
        stack<pair<int, int>> s;
        for (auto num : b) {
            s.push({0, num});
        }
        vector<int> path;
        int sum = 0;
        while (s.empty() == false) {
            pair<int, int> curr = s.top();
            s.pop();
            path.push_back(curr.second);
            mCnt[curr.second]--;
            int k = s.size();
            for (auto nxt : m[curr.second]) {
                if (mCnt[nxt] == 0) {
                    continue;
                }
                s.push({curr.first + 1, nxt});
            }
            if (path.size() == len || (k == s.size() && path.size() < len)) {
                if (path.size() == len) {
                    sum++;                    
                }
                while (s.size() > 0 && path.size() != s.top().first) {
                    mCnt[path.back()]++;
                    path.pop_back();
                }/*
                while (s.size() == 0 && path.size() > 0) {
                    mCnt[path.back()]++;
                    path.pop_back();
                }*/
            }
        }
        return sum;
    }
};
```