```c++
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto& email : emails) {
            string local;
            for (char c : email) {
                if (c == '@' || c == '+') break;
                if (c == '.') continue;
                local += c;
            }
            s.insert(local + email.substr(email.find('@')));
        }
        return s.size();
    }
};
```