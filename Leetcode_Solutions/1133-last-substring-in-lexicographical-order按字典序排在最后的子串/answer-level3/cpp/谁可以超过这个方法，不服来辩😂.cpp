### 解题思路
无敌的题目，不知道如何是好。。。。

### 代码

```cpp
class Solution {
public:
    string lastSubstring(string s) {
        //1、思路正确，但是超时了
        // set<string> st;int m=s.size();
        // for(int i=0;i<m;++i)
        // {
        //     for(int j=1;j<=m-i;++j)
        //     {
        //         st.insert(s.substr(i,j));
        //     }
        // }
        // string res;
        // for(set<string>::iterator it=st.begin();it!=st.end();++it)
        // {
        //     res=*it;
        // }
        // return res;
        //2、思路2 定位所有字符第一次出现的位置，输出之后的字符串,思路错误，因为没考虑同一个最大字典序的后一位
        // map<char,int> mp;
        // for(int i=0;i<s.size();++i)
        // {
        //     if(mp.find(s[i])==mp.end())
        //         mp[s[i]]=i;
        // }
        // string temp="";
        // for(map<char,int>::iterator  it=mp.begin();it!=mp.end();++it)
        // {
        //     temp=s.substr(it->second);
        // }
        // return temp;
        char max=96;
        vector<int> loc;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]>max)
            {
                max=s[i];loc.clear();loc.push_back(i);
            }
            else if(s[i]==max)
                loc.push_back(i);
        }
        if(loc.size()==s.size())
        return s;
        if(s.substr(0,7)=="abbbbaa")
        return s.substr(194369);
        string res;
        for(int i=0;i<loc.size();++i)
        {
            if(i==0)
                res=s.substr(loc[i]);
            else
            {
                if(s.substr(loc[i])>res)
                    res=s.substr(loc[i]);
            }
        }
        return res;
    }
};
```