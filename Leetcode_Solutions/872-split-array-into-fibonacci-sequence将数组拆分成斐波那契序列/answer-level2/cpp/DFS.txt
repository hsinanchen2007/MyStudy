### 解题思路
其实最关键的是我们判断当前数字加入后符合斐波那契，才放入。

### 代码

```cpp
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> v;
        DFS(S, 0, v);
        return ans;
    }
    void DFS(string s, int st, vector<int> &v)
    {
        if(find)
            return ;
        if(st == s.length())
        {
            if(v.size() > 2)
            {
                ans = v;
                find = true;
            }
            return ;
        }
        for(int i = st ; i < s.length() ; ++i)
        {
            string temp = s.substr(st, i - st + 1);
            long long tempNum = 0;
            for(auto ch : temp)
            {
                tempNum = tempNum * 10 + ch - '0';
                if(tempNum > INT_MAX)
                    return ;
            }
            if(to_string(tempNum) != temp)
                continue;
            if(v.size() >= 2)
            {
                long long sum = (long long)v.back() + (long long)v[v.size() - 2];
                if(tempNum != sum)
                    continue;
            }
            v.push_back((int)tempNum);
            DFS(s, i + 1, v);
            v.pop_back();
        }
    }
private:
    vector<int> ans;
    bool find = false;
};
```