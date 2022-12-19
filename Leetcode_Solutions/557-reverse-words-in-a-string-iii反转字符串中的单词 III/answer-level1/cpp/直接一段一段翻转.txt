执行用时 :20 ms, 在所有 C++ 提交中击败了93.38%的用户
内存消耗 :11.9 MB, 在所有 C++ 提交中击败了55.72%的用户
```
class Solution {
public:
    string reverseWords(string s) {
        if(s.length() <= 1) return s;
        
        int start =0;
        int end = 0;
        
        for(int i = 0; i < s.length()+1;i++){
          if(s[i] == ' ' || i == s.length()) {
              end = i-1;
              for(int m = start; m < (start+end+1)/2; m++){
                  char tmp = s[m];
                  s[m] = s[end-m+start];
                  s[end-m+start] = tmp;
              }
              start = i+1;
          }
        }
        
        return s;
    }
};
```
