```
class Solution {
public:
    char firstUniqChar(string s) {
            if(s.empty())  return ' ' ;
            int i;
            for(i=0;i<s.size();i++){
                if((s.find(s[i])==i)&&(s.find_last_of(s[i])==i)) //找的是s[i]第一个下标和最后一个下标是否一样
                    break;
                if(i==s.size()-1) return ' ';
            }
            return s[i];
    }
};
```
