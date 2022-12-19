```
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i++){
            int t_end=i+k<=s.length()?i+k-1:s.length()-1;
            reverse(s,i,t_end);
            i=t_end+k;
        }
        return s;
    }
    void reverse(string &s, int start, int end){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};
```
