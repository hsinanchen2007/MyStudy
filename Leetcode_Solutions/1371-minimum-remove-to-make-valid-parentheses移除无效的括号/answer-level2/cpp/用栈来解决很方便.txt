![1583578454(1).png](https://pic.leetcode-cn.com/86877908988ef056d693a6b5099241f73efe6b722ff75b0048d9cb4917bb419e-1583578454\(1\).png)
```
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.empty()) return s;
        int p1 = 0;
        int p2 = 1;
        stack<int> ans;
        for(int n = 0; n < s.size(); n++)
        {
            if(s[n] == '(') {ans.push(n);continue;}
            if(s[n] == ')')
            {
                if(!ans.empty()) ans.pop();
                else {s.erase(n,1);n--;}
            }
        }
        while(!ans.empty())
        {
            s.erase(ans.top(),1);
            ans.pop();
        }
        return s;
    }
};
```
