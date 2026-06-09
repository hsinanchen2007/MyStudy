```cpp
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        map<string, int> b;
        string d1, d2, d3;
        vector<string> ans;
        int cnt;
        for (auto it : cpdomains)
        {
            istringstream is(it);
            is >> cnt >> d1;
            b[d1] += cnt;

            d2 = d1.substr(d1.find('.') + 1);
            b[d2] += cnt;
            
            if(d2.find('.') != d2.npos) {
                d3 = d2.substr(d2.find('.') + 1);
                b[d3] += cnt;
            }
        }

        for(auto kv : b) {
            ans.push_back(to_string(kv.second) + ' ' + kv.first );
        }
        return ans;
    }
};
```
