```
class Solution {
public:
    string reverseWords(string s) {
        string stack, ans, temp = " ";
        while (!s.empty())
        {
            char tmp = *(s.end()-1);
            s.pop_back();
            if (tmp != ' ')
            {
                stack.push_back(tmp);
            }
            else
            {
                ans.insert(ans.begin(), stack.begin(), stack.end());
                ans.insert(ans.begin(), temp.begin(), temp.end());
                stack = "";
            }
        }
        ans.insert(ans.begin(), stack.begin(), stack.end());
        return ans;
    }
};
```
