```c++
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto& t : cpdomains) {
            int i = t.find(' ');
            int count = stoi(t.substr(0, i));
            string domain = t.substr(i + 1);
            m[domain] += count;
            for (int n = 0; n < domain.size(); n++) {
                if (domain[n] == '.') m[domain.substr(n + 1)] += count;
            }
        }
        vector<string> r;
        for (auto& p : m) {
            r.push_back(to_string(p.second) + " " + p.first);
        }
        return r;
    }
};
```