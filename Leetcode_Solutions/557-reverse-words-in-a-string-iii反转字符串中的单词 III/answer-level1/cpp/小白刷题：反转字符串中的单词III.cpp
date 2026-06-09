C++中没有现成的split函数，用strtok代替，分割后将字符串反转，最后拼接起来

代码：
```
class Solution {
public:
    string reverseWords(string s) {
        if (s == "")
            return s;
        else {
            string ans = "";
            const char* c = " ";
            char* p = strtok((char*)s.c_str(), c);
            while (p) {
                string temp = p;
                reverse(temp.begin(), temp.end());
                ans = ans + temp + " ";
                p = strtok(NULL, c);
            }
            ans.pop_back();
            return ans;
        }
    }
};
```
