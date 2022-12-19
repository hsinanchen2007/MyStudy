与kmp算法求子串位置类似，从s[i=0] 和s[j=1]位置开始进行匹配，直到j到达串尾。
```
class Solution {
public:
    string longestPrefix(string s) {
        if(s.length() < 2) return "";
        vector<int> next(s.length(), 0);
        next[0] = -1;
        int i = 0, j = 1;
        while(j < next.size()-1){
            if(i == -1 || s[i] == s[j])
                next[++j] = ++i;
            else
                i = next[i];
        }
        i = 0;
        j = 1;
        while(j != s.length()){
            if(i == -1 || s[i] == s[j]){
                i++;
                j++;
            }
            else
                i = next[i];
        }
        return s.substr(0,i);
    }
};
```
