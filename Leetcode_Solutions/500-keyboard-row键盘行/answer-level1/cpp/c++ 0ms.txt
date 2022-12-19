```
class Solution {
public:
    vector<string> s =  {"qwertyuiop","asdfghjkl","zxcvbnm"};

    bool Check(string str) {
        int index;

        for (int i = 0; i < 3; i++) {
            if (s[i].find(tolower(str[0])) < 100) {
                index = i;
                break;
            }
        }

        for (int i = 0; i < str.length(); i++) {
            if (s[index].find(tolower(str[i])) > 100) {
                return false;
            }
        }

        return true;
    }



    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            if(Check(words[i])){
                ans.push_back(words[i]);
            }

        }

        return ans;
    }
};
```
