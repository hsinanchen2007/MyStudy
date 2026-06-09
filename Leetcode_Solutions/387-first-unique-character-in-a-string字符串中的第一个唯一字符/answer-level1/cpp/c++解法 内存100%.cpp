```
class Solution {
public:
    int firstUniqChar(string s) {
        int* count = new int[256];
        for(int i = 0; i < 256; i++){
            count[i] = 0;
        }
        for(int i = 0; i < s.length(); i++){
            count[s[i]] = count[s[i]] + 1;
        }
        for(int i = 0; i < s.length(); i++){
            if(count[s[i]] == 1)
            return i;
        }
        return -1;
    }
};
```
