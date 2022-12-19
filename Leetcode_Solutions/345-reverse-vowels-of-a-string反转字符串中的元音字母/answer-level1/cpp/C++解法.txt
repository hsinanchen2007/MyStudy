```cpp
class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> isVowel;
        for (int i = 0; i < 26; i++)
            isVowel['a' + i] = false;
        isVowel['a'] = isVowel['e'] = isVowel['i'] = isVowel['o'] = isVowel['u'] = true;
        int low = 0, high = s.length() - 1;
        while (low < high) {
            while (low < high && !isVowel[tolower(s[low])]) low++;
            while (low < high && !isVowel[tolower(s[high])]) high--;
            char temp = s[low];
            s[low++] = s[high];
            s[high--] = temp;
        }
        return s;
    }
};
```
