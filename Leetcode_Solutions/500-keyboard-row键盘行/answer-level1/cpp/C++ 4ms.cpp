### 解题思路
创建数组对应26个字母的行数 注意大小写问题

### 代码

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string> ans;
        int len = words.size();
        int row[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        for (int i = 0; i < len; i++)
        {
            bool flag = 1;
            int wlen = words[i].length();
            for (int j = 0; j < wlen - 1; j++)
            {
                int a = words[i][j] >= 'a' ? words[i][j] - 'a' : words[i][j] - 'A', b = words[i][j + 1] >= 'a' ? words[i][j + 1] - 'a' : words[i][j + 1] - 'A';
                if (row[a] != row[b])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) ans.push_back(words[i]);
        }
        return ans;
    }
};
```