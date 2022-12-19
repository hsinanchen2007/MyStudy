### 解题思路
Maximum Nesting Depth of Two Valid Parentheses Strings

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int mx=0;
        int cnt=0;
        int flag=0;
        vector<int> v(seq.size(), 0); 
        for (int i = 0; i < seq.size(); ++ i)
        {
            if (seq[i] == '(')
            {
                cnt++;
                v[i] = cnt;
                mx = std::max(mx, cnt); 
            }
            else 
            {
                v[i] = cnt;
                cnt--;
            }
        }
        flag = mx >> 1; 
        for (auto& item : v)
        {
            item = item > flag ? 1 : 0; 
        }
        return v;
    }
};

```