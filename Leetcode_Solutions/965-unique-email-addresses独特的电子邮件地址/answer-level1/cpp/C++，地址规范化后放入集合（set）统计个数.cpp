```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> m;
        for(auto x : emails) {
            int at = x.find_first_of('@');
            int add = x.find_first_of('+');
            if (add == std::string::npos) {
                add = x.size();
            }

            string addr;
            for(int i = 0; i < x.size(); i++) {
                if((i < at && i < add && x[i] != '.') || i >= at){
                    addr.push_back(x[i]);
                }
            }
            //cout << addr << endl;
            m.insert(addr);
        }
        return m.size();
    }
};
```
