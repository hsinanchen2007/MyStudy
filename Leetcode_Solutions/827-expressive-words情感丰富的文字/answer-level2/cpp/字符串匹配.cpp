```
class Solution {
public://执行用时 :8 ms, 在所有 C++ 提交中击败了90.28%的用户
    int i,j,cnt,cnt1,res;
    char ch;
    bool flag;
    int expressiveWords(string s, vector<string>& words) {
        for(auto&str: words) {
            flag = true;
            for(i=j=0;i<s.length()&&j<str.length();) {
                if(s[i]==str[j]) {//计算相同字母在两个字符串中的数量
                    cnt=cnt1=0;ch = s[i];
                    while(i<s.length()&&s[i]==ch) i++,cnt++;
                    while(j<str.length()&&str[j]==ch) j++,cnt1++;
                    if((cnt!=cnt1)&&(cnt<3||cnt<cnt1))  {flag=false;break;}//注意数量相同可以看作没有扩充
                }else {flag=false;break;}
            }
            if(flag&&i==s.length()&&j==str.length()) res++;//两个字符串只有多出就剩余的就无法扩充成功
        }
        return res;
    }
};
```
