
1. 先将字符串分为两部分，一部分是本地地址，另一部分是@域名地址
2. 然后将本地地址的'+'与'.'去掉，你可以用find函数~
3. 再把各个部分字符串拼接，放入set，自动去重~~
```
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> e;
        for(int k = 0; k < emails.size(); ++k)
        {
            //先将地址分为两部分
            string local = "";
            string realm = "";
            string trans_emails = "";
            //int n = emails.size();
            int indexa = find(emails[k].begin(), emails[k].end(), '@') - emails[k].begin();
            int indexadd = find(emails[k].begin(), emails[k].end(), '+') - emails[k].begin();
            if(indexadd != emails[k].size())
                local = string(emails[k].begin(), emails[k].begin() + indexadd);
            else
                local = string(emails[k].begin(), emails[k].begin() + indexa);   
            realm = string(emails[k].begin() + indexa, emails[k].end());
            //继续过滤'.'
            for(int i = 0; i < local.size(); ++i)
            {
                if(local[i] != '.')
                    trans_emails += local[i];
            }
                trans_emails += realm;
                e.insert(trans_emails);
        }
        return e.size();
    }
};

```