```
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> char_stack;
        vector<int> ocurr_stack;
        for(int i = 0; i < s.length(); ++i)
        {
            if(char_stack.empty() || char_stack.back() != s[i])
            {
                char_stack.push_back(s[i]);
                ocurr_stack.push_back(1);
            }
            else
            {
                ocurr_stack.back()++;
            }
            if(ocurr_stack.back() == k)
            {
                char_stack.pop_back();
                ocurr_stack.pop_back();
            }
        }    
        string re;
        for(int i = 0; i < char_stack.size(); ++i)
        {
            while(ocurr_stack[i] > 0)
            {
                re += char_stack[i];
                ocurr_stack[i]--;
            }
        }
        return re;
    }
};
```
