首先建立临时变量temp1，用来保存字母与数字、顺便转大小写
然后建立临时变量temp2，翻转之，比较即可。
class Solution {
public:
    bool isPalindrome(string s) {
        string temp1;
        for(int i = 0 ; i < s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                temp1 += (s[i]-('a'-'A'));
            else if(isalnum(s[i]))
                temp1 += isupper(s[i])?;
        } 
        string temp2 = temp1;
        reverse(temp1.begin(),temp1.end());
        return temp1==temp2?true:false;
    }
};