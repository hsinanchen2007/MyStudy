```
class Solution {
public:
    string reverseWords(string s) {
        reverse(s,0,s.size()-1);
        int begin = 0;
        int count = 0;
        for (int i = 0;i<= s.size();i++) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s,begin,i-1);
                begin = i+1;
                count++;
            }
        }
        int tail = 0;    
        bool notbeign = true;                               //处理中间冗余空格
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' && notbeign) {
                continue;
            } else {
                notbeign = false;
            }
            if (i >= 1 && s[i] == ' ' && s[i-1] == ' ') continue;
             s[tail++] = s[i];
            if (s.size() == i && s[tail-2] == ' ') {
                s[tail-2] = s[tail-1];
            }
        }
        return s;
    }

    void reverse(string& s,int low,int high) {
        if (s.size() == 0) return;
        while (low<high) {
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
};
```
