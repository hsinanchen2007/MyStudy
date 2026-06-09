遍历字符串，设中间变量temp存储字符串，遇到空格时若temp不为空串说明单词完结，temp清空，数量+1，否则将字符插入temp

代码：
```
class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        string temp = "";
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                if (temp != "") {
                    ans++;
                    temp = "";
                }
            }
            else {
                temp.append(1, s[i]);
                if (i == len - 1)
                    ans++;
            }
        }
        return ans;
    }
};
```
