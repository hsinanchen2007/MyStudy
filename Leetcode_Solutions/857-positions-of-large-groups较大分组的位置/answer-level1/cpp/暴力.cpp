### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > ans;
        int cnt = 1, st = 0;
        for(int i = 1 ; i < S.length() ; ++i)
        {
            if(S[i] == S[i - 1])
            {
                cnt++;
            }
            else
            {
                if(cnt >= 3)
                {
                    vector<int> v;
                    v.push_back(st);
                    v.push_back(i - 1);
                    ans.push_back(v);
                }
                cnt = 1;
                st = i;
            }
        }
            if(cnt >= 3)
                {
                    vector<int> v;
                    v.push_back(st);
                    v.push_back(S.length() - 1);
                    ans.push_back(v);
                }
        return ans;
    }
};
```