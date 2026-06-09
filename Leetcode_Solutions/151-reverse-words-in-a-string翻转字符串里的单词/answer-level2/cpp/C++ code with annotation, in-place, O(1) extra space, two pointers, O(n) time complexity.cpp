#### My code is here:
```
class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        if(len==0) return s;
        int start=0, end=0;

        //remove leading spaces
        while(start<len && s[start]==' ') start++;
        s=s.substr(start);
        len-=start;
        start=0;

        //reverse entire string
        reverse(s.begin(), s.end());

        //remove trailing spaces
        while(start<len && s[start]==' ') start++;
        s=s.substr(start);
        len-=start;
        start=0;

        //reverse word by word
        while(start<len && end<=len)
        {
            //remove useless sapces between two words
            while(start<len && s.at(start)==' ') 
            {
                s.erase(start, 1);
                //end=++start;
                --len;
            }
            //find the end of current the word and reverse this word
            while(end<len && s.at(end)!=' ')
            {
                end++;
            }
            if(end == len || s.at(end)==' ')
            {
                reverse(s.begin()+start, s.begin()+end);
                //skip the useful space between two words
                start=++end;
            }
        }
        return s;
    }
};
```