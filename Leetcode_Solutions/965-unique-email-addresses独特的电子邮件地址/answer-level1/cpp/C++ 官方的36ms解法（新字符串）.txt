```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash;
        for (auto email : emails) {
            string name;
            int idx = email.find('@');
            for (auto c : email.substr(0, idx)) {
                if (c == '+') break;
                else if (c != '.') name += c;
            }
            string domain = email.substr(idx);
            hash.insert(name + domain);
        }
        return hash.size();
    }
};
```