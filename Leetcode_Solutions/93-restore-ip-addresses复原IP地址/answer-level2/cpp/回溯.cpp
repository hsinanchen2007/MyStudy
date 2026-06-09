```
class Solution {
private:
    bool isValid(string s)
    {
        if(s.size()>3 || s.size()<=0 || (s.size()>1 && s[0]=='0'))
            return false;
        int num = atoi(s.c_str());
        if(num>255||num<0)
            return false;
        else
            return true;
    }
    //当前剩余k段，out是前4-k段的字符串
    void restore(string s, int k, string out, vector<string>& res)
    {
        if(k==0)
        {
            if(s.empty())
                res.push_back(out);
        }
        else
        {
            //若还没组装完，就分别用长度1,2,3来试
            for(int i = 1;i<=3;i++)
            {
                if(s.size()>=i && isValid(s.substr(0,i)))
                {
                    if(k==1)
                        restore(s.substr(i),k-1,out+s.substr(0,i),res);
                    else
                        restore(s.substr(i),k-1,out+s.substr(0,i)+'.',res);
                }
            }
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s,4,"",res);
        return res;
        
    }
};
```
