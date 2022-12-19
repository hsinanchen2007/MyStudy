每次从队列中取出长度小于当前遍历长度的所有字符串，加上当前遍历字符，再加入到队列中。
```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        queue<string> q;
        q.push("");
        for(int i=0; i<S.length();i++)
        {
            char c = S[i];
            string t = q.front();
            while(t.length() < i + 1)
            {
                string c1, c2;
                if(c >= '0' && c <= '9')
                {
                    c1.push_back(c);
                    q.push(t + c1);
                }
                else if(c >= 'A' && c <= 'Z')
                {
                    c1.push_back(c);
                    c2.push_back((char)(c + 32));
                    q.push(t + c1);
                    q.push(t + c2);
                }
                else if(c >= 'a' && c <= 'z')
                {
                    c1.push_back(c);
                    c2.push_back((char)(c - 32));
                    q.push(t + c1);
                    q.push(t + c2);
                }    
                q.pop();
                t = q.front();
            }     
        }
        
        vector<string> res;
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
```