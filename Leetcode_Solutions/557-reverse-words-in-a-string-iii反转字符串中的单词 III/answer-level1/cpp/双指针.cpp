```c++
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        function<void(string& s, int i, int j)> reverse = [](string& s, int i, int j) {
            while (i < j) swap(s[i++], s[j--]);
        };
        for (int i = 0, j = 0; i < s.size(); ) {
            if (s[i] == ' ') i ++;
            else {
                j = i;
                while (j < s.size() && s[j] != ' ') j ++;
                reverse(s, i, j - 1); // [i, j)
                i = j;
            }
        }
        return s;
    }
};