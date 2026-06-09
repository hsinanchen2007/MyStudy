### [1324. 竖直打印单词](https://leetcode-cn.com/problems/print-words-vertically/)

#### 题解

  + 将各个单词的起点下标统计记录
  + 统计最大单词长，即竖直打印的行数
  + 最后记得删除行末空格
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    vector<string> printVertically(string s) {
        bool flag = true;
    vector<int> start;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ' && flag)
        {
            start.push_back(i);
            flag = false;
        }
        if(s[i] == ' ') flag = true;
    }
    int maxlen = 0;
    int ls = int(s.size());
    for(int i = 0; i < start.size(); i++)
        if(i == start.size() - 1)
            maxlen = max(maxlen, ls-start[i]);
        else maxlen = max(maxlen, start[i+1] - start[i] - 1);

    vector<string> ans;
    for(int i = 0; i < maxlen; i++)
        ans.push_back("");

    int x = 0;
    for(int i = 0; i < maxlen; i++)
        for(int j = 0; j < start.size(); j++)
           if((j == start.size()-1 && start[j] + i < s.size()) || (j < start.size() - 1  && start[j] + i < start[j+1]))
                ans[i] += s[start[j] + i];
           else
                ans[i] += ' ';
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = ans[i].size()-1; j >= 0; j--)
        {
            if(ans[i][j] != ' ')
            {
                ans[i] = ans[i].substr(0,j+1);
                break;
            }
        }
    }
    return ans;
    }
};
```