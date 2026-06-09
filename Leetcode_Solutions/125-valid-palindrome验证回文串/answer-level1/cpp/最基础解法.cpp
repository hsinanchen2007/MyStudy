将s转换为只有小写字母和数字的字符串
```
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0; i<s.length(); ++i)
        {
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
                str += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z')
                str += s[i] -'A' + 'a';
        }
        if(str == "")
            return true;
        string str1 = str;
        reverse(str.begin(), str.end());
        if(str1 == str)
            return true;
        else
            return false;
    }
};
```
时间复杂度O(n)