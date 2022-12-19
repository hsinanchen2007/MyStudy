
```c++ []
class Solution {
public:
    bool isPalindrome(string s) {
       
        string res = toTower(s);
         
        
        int len = res.size();
        if(len ==0||len ==1)
            return true;
        int mid;
        if(len%2==0)
        {
            mid = (len-1)/2;
            if(res[mid]!=res[mid+1])
                return false;
        }
        else
        {
            mid = len/2;
        }
        for(int i = 0; i < mid; i++)
        {
            if(res[i]!=res[len-1-i])
                return false;
        }
        return true;
        
    }
    string toTower(string s)
    {
        int len = s.size();
        string res;
       
        
        for(int i = 0; i< len; i++)
        {
            
            if(s[i]>='a'&&s[i]<='z')
                res+=s[i];
            else if(s[i] >= 'A'&&s[i]<='Z')
                res = res + (char)(s[i]+32);
            else if(s[i] >='0'&&s[i] <='9')
                res +=s[i];
            
            
        }
        
        return res;
    }
};
