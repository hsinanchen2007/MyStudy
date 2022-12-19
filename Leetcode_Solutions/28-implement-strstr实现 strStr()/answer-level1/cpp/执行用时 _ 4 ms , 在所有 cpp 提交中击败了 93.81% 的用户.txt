刚开始刷题，供大家参考；

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }

        for(int i = 0; i < haystack.size(); ++i){
            if(haystack[i] == needle[0]){
                int j = i;
                int n = 0;
                if(haystack.size() - j < needle.size()){
                    return -1;
                }
                while (j < haystack.size() && n < needle.size()){
                    if(haystack[j] != needle[n]){
                        break;
                    }
                    j++;
                    n++;
                }
                if(n == needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};
```
