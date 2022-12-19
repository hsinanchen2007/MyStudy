### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string,int> cnt;
        for(auto cp:cpdomains)
        {
            int index=cp.find(" ");
             int num = stoi(cp.substr(0, index));
            string sname=cp.substr(index+1);
            while(index>0)
            {
                cnt[sname]+=num;
                index=sname.find(".");
                sname=sname.substr(index+1);
            }
        }
        for(auto ct:cnt)
        {
            res.push_back(to_string(ct.second)+" "+ct.first);
        }
        return res;
    }
};
```