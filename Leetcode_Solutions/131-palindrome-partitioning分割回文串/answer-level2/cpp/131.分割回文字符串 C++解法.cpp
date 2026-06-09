### 解题思路
采用回溯方法和dfs
1.给定一个字符串，首先从头开始取一个子字符串，判断是否是回文字符串；
2.如果不是，此字符串忽略，继续取下一个子字符串；
3.如果是，将此子字符串加入临时的回文字符串集合buff，对余下的字符串继续dfs
4.字符串分割结束，将buff中保存的一个结果加入到结果集合中

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> result;
    bool isOk(string str)
    {
        return str == string(str.rbegin(),str.rend());
    }

    void dfs(string restr,vector<string>&cur)
    {
        int n = restr.length();
        if(n <= 0)
        {
            result.push_back(cur);
            return;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                string temphead = restr.substr(0,i+1);
                if(isOk(temphead))
                {
                    cur.push_back(temphead);
                    string secondstr = restr.substr(i+1);
                    dfs(secondstr,cur);
                    cur.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> tempstr;
        dfs(s,tempstr);
        return result;
    }
};
```