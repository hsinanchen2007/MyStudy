```cpp
class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());  // 整个字符串反转

        int start = 0, end = s.size() - 1;  // 跳过前后都空格
        while (start <= s.size() - 1 && s[start] == ' ') start ++;
        while (end >= 0 && s[end] == ' ') end --;
        if (end < start) return "";

        int tail = start;   // 删除中间重复的空格
        for (int i = start; i <= end; i++) {
            if (i - 1 >= 0 && s[i] == ' ' && s[i-1] == ' ')
                continue;
            s[tail++] = s[i]; 
        }
        end = tail - 1;

        // [start, end] 范围内的字符串不存在重复的空格了
        // 接下来反转每个单词
        int l = start;
        int r = start;
        while (l <= end && r <= end) {
            while (r <= end && s[r] != ' ')
                r++;           
            reverse(s.begin() + l, s.begin() + r);
            r ++;
            l = r;          
        } 
        return s.substr(start, end - start + 1);

    }
};
```