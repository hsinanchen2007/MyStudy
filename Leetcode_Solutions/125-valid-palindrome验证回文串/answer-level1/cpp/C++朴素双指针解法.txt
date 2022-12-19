```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int begin = 0;
        int end = s.size() - 1;
        // 从前往后找一个数字字符或者字母
        while (begin < end) {
           while (begin != end) {                
               // 判断是否为数字或者字母
               if (IsNumberOrLetter(s[begin]))
                   break;
               ++begin;
           }
            // 从后往前找一个数字字符或者字母
           while (begin < end) { 
               if (IsNumberOrLetter(s[end]))
                   break;
               --end;
            }

           if (begin < end) { 
               // 检测start和end位置字符是否相等 或者是否不区分大小的相等 
               if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32) 
                   return false;
               ++begin; 
               --end;
           }
        }
        return true;
    }
    
    bool IsNumberOrLetter(char c) {
        if (c >= '0' && c <= '9' ||
            c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
};
```
善用isalnum函数、tolower函数:
isalnum(char c):当c为数字0-9或字母a-z及A-Z时，返回非零值，否则返回零。
tolower(char c):把字母字符转换成小写,非字母字符不做出处理。
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};
```