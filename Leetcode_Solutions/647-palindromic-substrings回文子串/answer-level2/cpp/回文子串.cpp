```
class Solution {
public:
    //方法1：每一轮只判断长度为i的字符串，比较暴力，内存需求大
    int countSubstrings(string s) {
        if(s == "")
            return 0;

        int res = s.size();//至少有字符串长度个子串
        //至少有两个字符时
        //每一轮子串的长度是i，由于子串长度为1均为回文子串，所以从2开始
        if(s.size() > 1)
        {
            for(auto i = 2;i <= s.size();i++)
            {
                int p1 = 0;//从首字符开始
                int p2 = p1 + i - 1;
                while(p2 < s.size())
                {
                    if(isSubstrings(s,p1,p2))
                        res++;
                    p1++;
                    p2 = p1 + i - 1;
                }
            }
        }
        return res;
    }

    bool isSubstrings(string s,int p1,int p2)
    {
        while(p1 < p2)
        {
            if(s[p1] == s[p2])
            {
                p1++;
                p2--;
            }
            else
                return false;
        }
        return true;
    }


    //方法2：中心扩展
    int res = 0;//最好是放在private
    int countSubstrings(string s)
    {
        for(auto i = 0;i < s.size();i++)
        {
            extendSubstrings(s,i,i);//奇数长的子串
            extendSubstrings(s,i,i+1);//偶数长的子串
        }
        return res;
    }

    void extendSubstrings(string s,int p1,int p2)
    {
        while(p1 >= 0 && p2 < s.size() && s[p1] == s[p2])
        {
            //扩展
            p1--;
            p2++;
            res++;//个数加一
        }
    }
};
```
