set自动去重，设一set存储摩尔斯密码，返回set大小即可

代码：
```
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string func[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> s;
        for (int i = 0; i < words.size(); i++) {
            string code = "";
            for (int j = 0; j < words[i].length(); j++)
                code = code + func[words[i][j] - 'a'];
            s.insert(code);
        }
        return s.size();
    }
};
```
