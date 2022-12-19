![image.png](https://pic.leetcode-cn.com/1deb6d24b249b480732be054fedf9de7318544c5cc0319f9697d556732b6ed74-image.png)
解题思路：先拆分，得到最低级域名及个数，再往高级统计，并存入map中，最后将个数个域名转化为res并输出
```
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        vector<string> res;
        int index = 0;
        int num   = 0;
        string subitm;
        string ipname;
        for(auto itm:cpdomains)
        {
            index  = itm.find(' ');
            ipname = itm.substr(index+1);
            num    = atoi(itm.substr(0, index).c_str());
            count[ipname] += num;
            index  = -1;
            while((index = ipname.find('.', index+1)) > 0)
            {
                subitm = ipname.substr(index+1);
                count[subitm] += num;
            }
        }
        for(auto itm2:count)
        {
            res.push_back(to_string(itm2.second) + " " + itm2.first);
        }
        return res;
    }
```
