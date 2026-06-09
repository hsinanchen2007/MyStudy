```
class Solution {
public:
    int strStr(string haystack,string needle){
        if(needle.empty()) return 0;
        int n1,n2;
        n1=haystack.size();
        n2=needle.size();
        for(int start=0;start<n1-n2+1;start++){
            if((haystack.substr(start,n2))==needle) return start;
            
        }
        
            return -1;
    }
};
```
