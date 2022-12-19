### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int N = 14010;
        int son[N][26];
        int cnt[N];
        int idx = 0;

        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < words.size(); i ++ )
        {
            int p = 0;
            for (int j = words[i].size() - 1; j >= 0; j -- )
            {
                int u = words[i][j] - 'a';
                if (!son[p][u]) son[p][u] = ++ idx;
                p = son[p][u];
            }
            cnt[p] = words[i].size() + 1;
        }

        int res = 0;
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            bool have = false;
            for (int i = 0; i < 26; i ++ )
                if (son[t][i])
                {
                    have = true;
                    q.push(son[t][i]);
                }
            if (!have) res += cnt[t];
        }
        
        return res;
    }
};
```