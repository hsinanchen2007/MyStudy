### 解题思路

### 代码

```cpp
class Solution {
public:
    int kSimilarity(string A, string B) {
        queue<pair<string, int>> q;
        q.push({A, 0});
        set<string> vis;
        vis.insert(A);
        int step = 0;
        while (q.empty() == false) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                pair<string, int> p = q.front();
                q.pop();
                string curr = p.first;
                int k = p.second;
                if (curr == B) {
                    return step;
                }
                while (k < A.size() && curr[k] == B[k]) {
                    k++;
                }
                for (int i = k + 1; i < A.size(); i++) {
                    if (curr[i] == B[i]) { // 非常关键
                        continue;
                    }
                    if (curr[i] == B[k]) {
                        swap(curr[i], curr[k]);
                        if (vis.find(curr) == vis.end()) {
                            q.push({curr, k + 1});
                            vis.insert(curr);
                        }
                        swap(curr[i], curr[k]);
                    }
                }
            }
            step++;
        }
        return step;
    }
};
/*class Solution {
public:
    struct TreeNode { // 记录向右滑过k次之后B的状态
        int k;
        int skip = 0; // 跳过次数
        string s;
        unordered_map<char, set<int>> m;
        TreeNode (int idx, string str, unordered_map<char, set<int>> tmp) : k(idx), m(tmp), s(str) {};
    };
public:
    int kSimilarity(string A, string B) {
        unordered_map<char, set<int>> m;
        for (int i = 0; i < B.size(); i++) {
            m[B[i]].insert(i);
        }
        TreeNode* root = new TreeNode(0, B, m);
        queue<TreeNode*> q;
        q.push(root);
        int ans = INT_MAX;
        while (q.empty() == false) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->s == A) {
                ans = min(ans, curr->k - curr->skip);
                continue;
            }
            if (A[curr->k] == curr->s[curr->k]) {
                int idx = curr->k + 1;
                while (A[idx] == curr->s[idx]) {
                    idx++;
                }
                TreeNode* node = new TreeNode(idx, curr->s, curr->m);
                node->skip = curr->skip + (idx - curr->k);
                q.push(node);
                continue;   
            }
            for (auto idx : curr->m[A[curr->k]]) {
                if (idx < curr->k || A[idx] == curr->s[idx]) {
                    continue;
                }
                TreeNode* node = new TreeNode(curr->k + 1, curr->s, curr->m);
                node->m[A[curr->k]].erase(idx);
                node->m[B[curr->k]].insert(idx);
                node->s[idx] = node->s[curr->k];
                node->s[curr->k] = A[curr->k];
                node->skip = curr->skip;
                q.push(node);
            }
        }
        return ans;
    }
};*/
```