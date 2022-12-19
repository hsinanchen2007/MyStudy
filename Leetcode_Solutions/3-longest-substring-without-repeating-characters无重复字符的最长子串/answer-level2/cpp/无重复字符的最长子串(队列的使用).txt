### 解题思路
对于s[i]检查是否标记:
1.未标记则标记后入队
2.已标记则将其与其之前的字符出队
### 代码

```cpp
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> vis(130,0);
        queue<char> q;
        int len=0;

        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]]) 
            {
                if(q.size()>len) len=q.size();

                while(q.front()!=s[i]) 
                {
                    vis[q.front()]=0;
                    q.pop();
                }
                q.pop();
            }

            vis[s[i]]=1;
            q.push(s[i]);
        }
    
        return len>q.size() ? len:q.size();
    }
};
```