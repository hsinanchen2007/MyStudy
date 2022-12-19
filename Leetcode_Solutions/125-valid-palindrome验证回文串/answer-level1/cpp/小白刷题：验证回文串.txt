双指针，一头一尾，遍历分情况比较头尾指针对应字符，并挪动相应指针

代码：
```
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len < 2)
            return true;
        else {
            int i = 0, j = len - 1;
            while (i <= j) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[j] >= '0' && s[j] <= '9') {
                        if (s[i] != s[j])
                            return false;
                        else {
                            i++;
                            j--;
                        }
                    }
                    else if (s[j] >= 'A' && s[j] <= 'Z')
                        return false;
                    else if (s[j] >= 'a' && s[j] <= 'z')
                        return false;
                    else
                        j--;
                }
                else if (s[i] >= 'A' && s[i] <= 'Z') {
                    if (s[j] >= '0' && s[j] <= '9') 
                        return false;
                    else if (s[j] >= 'A' && s[j] <= 'Z') {
                        if (s[i] != s[j])
                            return false;
                        else {
                            i++;
                            j--;
                        }
                    }
                    else if (s[j] >= 'a' && s[j] <= 'z') {
                        if (s[i] != s[j] - 32)
                            return false;
                        else {
                            i++;
                            j--;
                        }
                    }
                    else
                        j--;
                }
                else if (s[i] >= 'a' && s[i] <= 'z') {
                    if (s[j] >= '0' && s[j] <= '9') 
                        return false;
                    else if (s[j] >= 'A' && s[j] <= 'Z') {
                        if (s[i] != s[j] + 32)
                            return false;
                        else {
                            i++;
                            j--;
                        }
                    }
                    else if (s[j] >= 'a' && s[j] <= 'z') {
                        if (s[i] != s[j])
                            return false;
                        else {
                            i++;
                            j--;
                        }
                    }
                    else
                        j--;
                }
                else
                    i++;
            }
            return true;
        }
    }
};
```
