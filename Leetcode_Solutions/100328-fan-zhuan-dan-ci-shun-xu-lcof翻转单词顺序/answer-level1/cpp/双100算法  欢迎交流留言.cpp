![960be0d1fe2cfd9ed2ee633a1f38022.png](https://pic.leetcode-cn.com/79ed4e1cb6a99f9275c0de6c977edeaa3bfc802accf24625d77a3d4d93f45ccc-960be0d1fe2cfd9ed2ee633a1f38022.png)




```
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int len = 0;
        string ans = "";
        for(int m = s.size()-1; m >=0; m--)
        {
            if(s[m]==' '&&len!=0)
            {
                ans += s.substr(m+1,len)+ " ";len = 0; continue;
            }
            if(s[m]!= ' ')len++;
        }
        if(len !=0) ans += s.substr(0,len) + " ";
        if(ans.size()>0)ans.erase(ans.size()-1,1);
        return ans;

    }
};
```
