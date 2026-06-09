- dp记录的是以当前反括号所匹配的正括号这个区间的长度。
- 遍历的过程中可以判断当前区间是否和前一个区间相连，如果不相连也没关系，直接+0，也不影响结果。
```
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> cache;
        int max_len = 0;
        int* dp = new int[s.size()];
        for(int i=0;i<s.size();i++)
            dp[i] = 0;
        for(int i=0;i<s.size();i++)
        {
            char cur_char = s[i];
            if(cur_char=='(')
            {
                cache.push(i);
            }
            else
            {
                if(cache.empty())
                {
                    continue;
                }
                int match_index = cache.top();
                cache.pop();
                int cur_len = i-match_index+1;
                //区间相连的情况，如果不相连也没关系
                if (match_index-1>=0)
                    cur_len += dp[match_index-1];
                dp[i] = cur_len;
                if(cur_len>max_len)
                    max_len = cur_len;
            }
        }
        return max_len;
    }
};
```
