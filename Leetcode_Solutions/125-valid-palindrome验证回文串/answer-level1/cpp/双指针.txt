``` C++
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1) return true;
        int start=0,end=s.size()-1;
        while(start<end)
        {
            if((s[start]>='0'&&s[start]<='9')||(s[start]>='a'&&s[start]<='z')||(s[start]>='A'&&s[start]<='Z'))
                start=start;
            else
            {
                start++;
                continue;//要跳出本次循环
            }
            if((s[end]>='0'&&s[end]<='9')||(s[end]>='a'&&s[end]<='z')||(s[end]>='A'&&s[end]<='Z'))
                end=end;
            else
            {
                end--;
                continue;//要跳出本次循环
            }
            //‘0’与‘P’差32
            if(start<end&&(s[start]==s[end]||(s[start]>='A'&&s[start]<='Z'&&s[start]+32==s[end])||s[start]==s[end]+32&&s[end]>='A'&&s[end]<='Z'))
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};
```