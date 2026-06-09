### 解题思路
我写的应该算回溯吧。。。

### 代码

```cpp
class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        string cur;
        help(s,cur,3);
        return res;
    }
    void help(string &s,string &cur, int points)
    {
        if(s=="")
        return;
        if(points==0)
        {
            int num=stringToInt(s);
            if((s.size()==1&&num>=0&&num<=9)||
                (s.size()==2&&num>=10&&num<=99)||
                (s.size()==3&&num>=100&&num<=255))
            {
                cur+=s;
                res.push_back(cur);
            }
            return;
        }
        for(int i=1;i<=3;++i)
        {
            if(s.size()<i)
            continue;
            int num=stringToInt(s.substr(0,i));
            if((i==1&&num>=0&&num<=9)||
                (i==2&&num>=10&&num<=99)||
                (i==3&&num>=100&&num<=255))
            {
                string temp=cur;
                cur+=s.substr(0,i);
                cur+='.';
                string sstr=s.substr(i);
                help(sstr,cur,points-1);
                cur=temp;
            }
        }
    }
    int stringToInt(string s)
    {
        stringstream ssm;
        ssm<<s;
        int num;
        ssm>>num;
        return num;
    }
    string intToString(int num)
    {
        stringstream ssm;
        ssm<<num;
        string s;
        ssm>>s;
        return s;
    }
};
```