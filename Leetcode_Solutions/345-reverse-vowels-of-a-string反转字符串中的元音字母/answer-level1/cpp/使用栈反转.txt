正向入，再正向出。

class Solution {
public:
    string reverseVowels(string s) {
        string cmpStr("aeiouAEIOU");
        for (auto const c : s)
        {
            if (cmpStr.find(c) != string::npos)
            {
                m_stack.push(c);
            }
        }

        int len = s.size();
        for (int i = 0; i < len; i++)   
        {
            char c = s[i];
            if (cmpStr.find(c) != string::npos)
            {
                s[i] = m_stack.top();
                m_stack.pop();
            }
        }

        return s;
    }
private:
    stack<char> m_stack;
};