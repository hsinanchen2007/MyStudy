```
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        vector<string> ret;
        int i = 0;
        int n = 0;
        string subdom;
        string name;
        for(auto dom:cpdomains)
        {
            i = dom.find(' ');
            name = dom.substr(i+1);
            n = atoi(dom.substr(0, i).c_str());
            count[name] += n;
            i = -1;
            while((i = name.find('.', i+1)) > 0)
            {
                subdom = name.substr(i+1);
                count[subdom] += n;
            }
        }
        for(auto m:count)
        {
            ret.push_back(to_string(m.second) + " " + m.first);
        }
        return ret;
    }
};
```
