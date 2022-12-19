
算法参考 https://zhuanlan.zhihu.com/p/20611132

```c++
class Solution {
public:
    bool canWin(string s) {
        int n = s.size();
        if(n < 2) return false;
        vector<int> state = _get_state(s);
        int maxx = 0;
        for(int x: state) maxx = max(maxx, x);
        if(maxx < 2) return false;
        vector<int> g(maxx + 1, 0);
        vector<int> sub;
        for(int x = 2; x <= maxx; ++x)
        {
            sub.clear();
            for(int i = 0; i * 2 <= x - 2; ++i)
            {
                // (0, n - 2) (1, n - 3), ...
                // (i, n - 2 - i)
                sub.push_back(g[i] ^ g[x - 2 - i]);
            }
            g[x] = _fmn(sub);
        }
        for(int x: state) cout << x << " ";
        cout << endl;
        for(int i: g) cout << i << " ";
        cout << endl;
        int res = 0;
        for(int x: state) res ^= g[x];
        return res > 0;
    }

private:
    int _fmn(vector<int>& sub)
    {
        int n = sub.size();
        for(int i = 0; i < n; ++i)
        {
            if(sub[i] == -1) continue;
            int nxt = sub[i];
            while(nxt < n && sub[nxt] != -1)
            {
                int tmp = sub[nxt];
                sub[nxt] = -1;
                nxt = tmp;
            }
        }
        for(int i = 0; i < n; ++i)
            if(sub[i] != -1)
                return i;
        return n;
    }

    vector<int> _get_state(string& s)
    {
        int n = s.size();
        int i = 0;
        vector<int> result;
        while(i < n)
        {
            while(i < n && s[i] == '-')
                ++i;
            if(i == n) break;
            int j = i;
            while(j < n && s[j] == '+')
                ++j;
            int len = j - i;
            if(len >= 2)
                result.push_back(len);
            i = j;
        }
        return result;
    }
};

```
