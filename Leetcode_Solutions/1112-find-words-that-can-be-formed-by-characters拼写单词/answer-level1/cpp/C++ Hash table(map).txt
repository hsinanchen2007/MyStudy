```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        map<char, int> char_res;
        for (int i = 0; i < chars.length(); i++) {
            char_res[chars[i]]++;
        }
        for (int i = 0; i < words.size(); i++) {
            map<char, int> temp_res;
            bool flag = true;
            for (int j = 0; j < words[i].length(); j++) {
                temp_res[words[i][j]]++;
            }
            for (int k = 0; k < words[i].length(); k++) {
                if (temp_res[words[i][k]] > char_res[words[i][k]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res += words[i].length();
            }
        }
        return res;
    }
};
```