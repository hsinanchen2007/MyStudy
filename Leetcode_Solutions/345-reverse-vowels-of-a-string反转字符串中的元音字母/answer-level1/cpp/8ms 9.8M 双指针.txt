```
class Solution {
public:
    bool isYuanYin(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isYuanYin(s[left])) left++;
            while (left < right &&!isYuanYin(s[right])) right--;
            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            } 
        }
        return s;
    }
};
```
