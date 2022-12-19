```
class Solution {
public:
    //多分隔符切割函数
    map<string,int> split(string paragraph, string delimiters)
    {
        map<string,int> result;
        int idx = 0;
        for(int i=0;i<paragraph.size();i++)
        {
            bool isDelimiter = false;
            for(auto d : delimiters)
            {
                if(paragraph[i] == d) 
                {
                    isDelimiter = true;
                    break;
                }
            }
            // 遇到一个标点，把之前的作为一个单词
            if(isDelimiter == true)
            {
                string word = paragraph.substr(idx,i-idx);
                if(word != "")
                {
                    transform(word.begin(),word.end(),word.begin(),::tolower);
                    result[word] += 1;
                }
                idx = i + 1;
            }
        }

        string word = paragraph.substr(idx,paragraph.size()-idx);
        if(word != "")
        {
            transform(word.begin(),word.end(),word.begin(),::tolower);
            result[word] += 1;
        }
        return result;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        string delimiters = " !?',;.";
        map<string,int> words = split(paragraph, delimiters);
        for(auto key : banned) words[key] = 0;
        string res = "";
        int max = 0;
        for(auto it : words)
        {
            if(it.second > max)
            {
                res = it.first;
                max = it.second;
            }
        }
        return res;
    }
};
```