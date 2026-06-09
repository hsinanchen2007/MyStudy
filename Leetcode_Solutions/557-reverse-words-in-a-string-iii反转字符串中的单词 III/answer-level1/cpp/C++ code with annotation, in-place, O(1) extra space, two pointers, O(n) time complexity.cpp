#### My code is here:
```
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        int len=(int)s.size(), start=0, end=0;
        while(start<len && end<=len)
        {
            //reverse word by word and skip the whitespaces between two words
            if(end==len || s.at(end)==' ')
            {
                reverse(s.begin()+start, s.begin()+end);
                start=++end;
            }
            //find the end of current word(' ' or '\0')
            else end++;
        }
        return s;
    }
};
```