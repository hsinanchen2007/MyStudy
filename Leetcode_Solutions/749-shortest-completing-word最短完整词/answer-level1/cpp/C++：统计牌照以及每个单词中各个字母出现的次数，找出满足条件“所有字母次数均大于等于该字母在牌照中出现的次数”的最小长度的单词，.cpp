```
class Solution {
public:
    vector<int> statistic(string word)
    {
        vector<int> letters(26,0);
        for(int i=0;i<word.length();i++)
        {
            char c = word[i];
            if(!(c>='A'&&c<='Z') && !(c>='a'&&c<='z'))
                continue;
            if(c>='A' && c<='Z')
                c += 32;
            letters[c - 'a']++;
        }
        return letters;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res = "";
        vector<int> license = statistic(licensePlate);
        for(int i=0;i<words.size();i++)
        {
            vector<int> word = statistic(words[i]);
            bool flag = true;
            for(int j=0;j<26;j++)
            {
                if(word[j] < license[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true && (res == "" || words[i].length() < res.length()))
                res = words[i];    
        }
        return res;
    }
};
```