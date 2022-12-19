```
class Solution {
public:

    bool exist(vector<string>& words, string word)
    {
        while(word != "")
        {
            if(find(words.begin(), words.end(), word) == words.end())
                return false;
            word = word.substr(0,word.length()-1);
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        string res = "";
        for(auto word : words)
        {
            if(exist(words,word))
            {
                if(res == "" || res.length() < word.length() || (res.length() == word.length() && res > word))
                {
                    res = word;
                }
            }
        }

        return res;
    }
};
```