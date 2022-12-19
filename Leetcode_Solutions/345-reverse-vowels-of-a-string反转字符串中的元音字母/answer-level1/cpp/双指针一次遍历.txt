**两个指针同时为元音字母时交换，否者不为元音的指针加1或减1**
class Solution {
public:
    string reverseVowels(string s) {
        if(s.size()<=1) return s;
        int start=0,end=s.size()-1;
        while(start<end)
        {
            if(s[start]!='a'&&s[start]!='e'&&s[start]!='i'&&s[start]!='o'&&s[start]!='u'
               &&s[start]!='A'&&s[start]!='E'&&s[start]!='I'&&s[start]!='O'&&s[start]!='U')
            {
                start++;
                continue;
            }
            if(s[end]!='a'&&s[end]!='e'&&s[end]!='i'&&s[end]!='o'&&s[end]!='u'
              &&s[end]!='A'&&s[end]!='E'&&s[end]!='I'&&s[end]!='O'&&s[end]!='U')
            {
                end--;
                continue;
            }
            char temp=s[end];
            s[end]=s[start];
            s[start]=temp;
            start++;
            end--;
            
        }
        return s;
        
    }
};