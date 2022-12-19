```
void rotateStr(string& s, int left, int right) {
        for (int i = left; i < (right+left+1) / 2; ++i) {
            std::swap(s[i], s[right+left-i]);    
        }
    }
    
    string reverseWords(string s) {
        // reverse all
        int len = s.length();
        rotateStr(s, 0, len - 1);
        
        // clear space and reverse word
        bool pre_words = s[0] != ' ';
        int left = 0, right = 0;
        while (right < s.length()) {
            if (!pre_words && s[right] == ' ') {
                right++;
            } else if (pre_words && s[right] == ' ') {
                pre_words = false;
                s[left++] = s[right++];
            } else {
                s[left++] = s[right++];
                pre_words = true;
            }
        }
        if (s[left-1] == ' ') //avoid right space
            left--;
        s.resize(left);
        
        left = 0;
        right = 0;
        while (right < s.length()) {
            if (s[right] == ' ') {
                rotateStr(s, left, right-1);
                right++;
                left = right;
            } else {
                 right++;
            }
        }
        rotateStr(s, left, right-1);
        return s;
    }
```
