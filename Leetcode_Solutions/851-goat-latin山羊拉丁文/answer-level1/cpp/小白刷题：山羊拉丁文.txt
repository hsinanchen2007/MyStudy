用空格进行分割，之后按规则构造新单词并插入返回值字符串中

代码：
```
class Solution {
public:
    string toGoatLatin(string S) {
        S.append(1, ' ');
        int len = S.length();
        int order = 1;
        string temp = "";
        string ans = "";
        for(int i = 0; i < len; i++) {
            if (S[i] == ' ') {
                if (!(temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U')) {
                    temp.append(1, temp[0]);
                    temp.erase(0, 1);
                }
                ans = ans + temp + "ma";
                ans.append(order, 'a');
                ans.append(1, ' ');
                order++;
                temp = "";
            }
            else
                temp.append(1, S[i]);
        }
        ans.pop_back();
        return ans;
    }
};
```
