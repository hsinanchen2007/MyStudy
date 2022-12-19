超时，仅做记录，等待优化

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dic(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(endWord);
        if(dic.find(endWord) == dic.end())
            return res;
        vector<string> curRes;
        vector<string> curLadders;
        curLadders.push_back(beginWord);
        FindCurladder(res, curRes, dic, curLadders, endWord);
        if(res.size() > 1)
        {
            int minLen = res[0].size();
            vector<string> temp;
            for(int i = 1; i < res.size(); i++)
            {
                if(res[i].size() < minLen)
                    minLen = res[i].size();
            }
            vector<vector<string>>::iterator it;
            for(it = res.begin(); it != res.end();)
            {
                if(it->size() > minLen)
                {
                    it = res.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        return res;
    }
    
    void FindCurladder(vector<vector<string>>& res, vector<string>& curRes, unordered_set<string>& dic, const vector<string>& curLadders, const string& endWord)
    {
        for(int i = 0; i < curLadders.size(); i++)
        {
            vector<string> resTemp = curRes;
            resTemp.push_back(curLadders[i]);
            if(curLadders[i] == endWord)
            {
                res.push_back(resTemp);
                return;
            }
            vector<string> nextLevelLadders;
            unordered_set<string> curDic = dic; 
            MatchWords(nextLevelLadders, curLadders[i], curDic);
            FindCurladder(res, resTemp, curDic, nextLevelLadders, endWord);
        }        
    }
    
    void MatchWords(vector<string>& res, string curWord, unordered_set<string>& dic)
    {
        if(dic.size() == 0)
            return;
        for(int i = 0; i < curWord.size(); i++)
        {
            string words = curWord;
            for(char c = 'a'; c <= 'z'; c++)
            {
                if(words[i] == c)
                    continue;
                words[i] = c;
                if(dic.find(words) != dic.end())
                {
                    res.push_back(words);
                    dic.erase(words);
                }
            }
        }
    }
};