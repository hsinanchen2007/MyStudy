### 解题思路
map<string, int> hashMap 保存每个子域名的访问次数

### 代码

```cpp
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
         vector<string> ans;
        map<string, int> hashMap;
        int n = 0;
        int i = 0;
        string name;
        string subdom;
        for (auto domain : cpdomains)
        {
            i = domain.find(' ');
            //截取域名
            name = domain.substr(i + 1);
            //获得访问次数，atoi(): string转int
            n = atoi(domain.substr(0, i).c_str());
            //保存最长的子域名
            hashMap[name] += n;
            i = -1;
            while ((i = name.find('.', i + 1)) != string::npos)
            {
                //获取子域名
                subdom = name.substr(i + 1);
                //更新子域名访问次数
                hashMap[subdom] += n;
            }
        }

        //保存结果
        for (auto m : hashMap)
        {
            ans.push_back(to_string(m.second) + " " + m.first);
        }
        //返回结果
        return ans;
    }

};
```