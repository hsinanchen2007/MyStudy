

### 代码

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> help;

        for(int i=1;i<=n;i++)
            help.push_back(to_string(i));
        sort(help.begin(),help.end());
        for(string h:help)
            ans.push_back(stoi(h));//stoi()将字符串转化为整数

        return ans;
    }
};
```