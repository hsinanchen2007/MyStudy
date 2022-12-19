```
class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        string temp;
        vector<string> words;

        int max_len = 0;
        while(getline(ss, temp, ' ')){
            words.push_back(temp);
            max_len = max_len>temp.size() ? max_len : temp.size();
        }

        vector<string> ret(max_len, "");
        for(int j=0; j<max_len; j++){
            for(int i=0; i<words.size(); i++){
                ret[j] += j>=words[i].size() ? ' ' : words[i][j];
            }
        }

        for(int i=0; i<max_len; i++){
            int j=words.size()-1;
            while(ret[i][j] == ' ') j--;
            ret[i] = ret[i].substr(0, j+1);
        }

        return ret;
    }
};
```
