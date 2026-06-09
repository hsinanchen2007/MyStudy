```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int firstMatch = -1;
        int needlePointer = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                firstMatch = i;
                if (firstMatch + needle.size() > haystack.size()) {
                    return -1;
                }
                for (int j = i; j < haystack.size(); j++,++needlePointer) {
                    if (haystack[j] != needle[needlePointer]) {
                        firstMatch = -1;
                        needlePointer = 0;
                        break;
                    }
                    
                    if (needlePointer == needle.size()-1) {
                        return firstMatch;
                    }
                }
            }
        }
        return firstMatch;
    }
};
```
