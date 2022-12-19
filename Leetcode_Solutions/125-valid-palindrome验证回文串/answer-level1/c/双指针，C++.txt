```
class Solution {
public:
    bool isAlphaOrDigit(char c){
        return isdigit(c) || isalpha(c);
    }
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 0){
            //空串是回文串
            return true;
        }
        int i = 0, j = len - 1;
        while (i < j){
            if (isAlphaOrDigit(s[i]) && isAlphaOrDigit(s[j]) ){
                //两端都是字母或者数字
                if (isalpha(s[i])){
                    //是字母则统一转成小写字母后进行比较
                    s[i] = tolower(s[i]);
                }
                if (isalpha(s[j])){
                    s[j] = tolower(s[j]);
                }

                if (s[i] == s[j]){
                    i ++;
                    j --;
                    continue;
                }else{
                    return false;
                }
            }
            //两端不都是字母
            if (!isAlphaOrDigit(s[i])){
                i ++;
            }
            if (!isAlphaOrDigit(s[j])){
                j --;
            }
        }
        return true;
    }
};
```
