### 解题思路

如果以'0'或'a'作为base比较offset，则无法区分字母和数字; 好在可以直接把 char字符作为 int 类型比较，只要做大小写转换即可。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n <= 1)
            return true;
        int i = 0;
        int j = n - 1;
        while(i < j) {
            while(i < j && !validChar(s[i]))
                i++;
            while(i < j && !validChar(s[j]))
                j--;
            if(!equalChar(s[i], s[j])) {
                // cout << s[i] << "," << s[j] << endl;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool validChar(char c) {
        if(c >= '0' && c <= '9')
            return true;
        if(c >= 'a' && c <= 'z')
            return true;
        if(c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
    
    bool equalChar(char a, char b) {
        
        int d1 = charToInt(a);
        int d2 = charToInt(b);
        return d1 == d2;
    }
    
    int charToInt(char c) {
        if(c >= '0' && c <= '9')
            return c;
        if(c >= 'a' && c <= 'z')
            return c;
        if(c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        return -1;
    }
};
```