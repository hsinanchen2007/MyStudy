```cpp
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string, int> cnt;
        for (auto word : cpdomains) {
            int index = word.find(' ');
            int num = stoi(word.substr(0, index));
            string dmName = word.substr(index + 1);

            while (index > 0) {
                cnt[dmName] += num;
                index = dmName.find('.');
                dmName = dmName.substr(index + 1);
            }
        }

        for (auto c : cnt)
            res.push_back(to_string(c.second) + " " + c.first);

        return res;
    }
};
```