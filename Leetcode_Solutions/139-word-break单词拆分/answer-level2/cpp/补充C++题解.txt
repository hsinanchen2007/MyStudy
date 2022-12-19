class Solution {
    bool isContain(const string &a, const vector<string> &wordDict)
    {
        for (size_t i = 0; i < wordDict.size(); i++) {
            if (a.compare(wordDict[i]) == 0) {
                return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.empty()) {
            return false;
        }
        vector<int> visited(s.length() + 1, 0);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (t == s.length()) {
                return true;
            } else if (t > s.length()) {
                continue;
            }
            
            if (visited[t] == 0)
            {
                for (size_t i = t; i < s.length(); i++) {
                    string temp = s.substr(t,i - t + 1);
                    if (isContain(s.substr(t,i - t + 1),wordDict))
                    {   
                        q.push(i + 1);
                    }           
                }
                visited[t] = 1;
            }
        }
        return false;
    }
};