```
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> mp;
        int mn = words.size();
        int n = 0;
        int i, j;
        for(i=0; i<words.size(); i++)
        {
            mp[words[i]].push_back(i);
        }
        for(i=0; i<mp[word1].size(); i++)
        {
            for(j=0; j<mp[word2].size(); j++)
            {
                n = abs(mp[word1][i] - mp[word2][j]);
                if(n < mn)
                {
                    mn = n;
                }
            }
        }
        return mn;
    }
};
```
方法二，用两个vector分别记录两个单词的位置
```
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int mn = words.size();
        int n = 0;
        int i, j;
        vector<int> v1, v2;
        for(i=0; i<words.size(); i++)
        {
            if(words[i] == word1)
            {
                v1.push_back(i);
            }
            else if(words[i] == word2)
            {
                v2.push_back(i);
            }
        }
        for(i=0; i<v1.size(); i++)
        {
            for(j=0; j<v2.size(); j++)
            {
                n = abs(v1[i] - v2[j]);
                if(n < mn)
                {
                    mn = n;
                }
            }
        }
        return mn;
    }
};
```
方法三，用两个变量分别记录两个单词最后出现的左边，并更新最小距离
```
class Solution {
public:
    int shortestDistance1(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> mp;
        int mn = words.size();
        int n = 0;
        int i, j;
        for(i=0; i<words.size(); i++)
        {
            mp[words[i]].push_back(i);
        }
        for(i=0; i<mp[word1].size(); i++)
        {
            for(j=0; j<mp[word2].size(); j++)
            {
                n = abs(mp[word1][i] - mp[word2][j]);
                if(n < mn)
                {
                    mn = n;
                }
            }
        }
        return mn;
    }
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int mn = words.size();
        int i;
        int i1 = -mn, i2 = -mn;
        for(i=0; i<words.size(); i++)
        {
            if(words[i] == word1)
            {
                i1 = i;
                mn = min(mn, i1-i2);
            }
            else if(words[i] == word2)
            {
                i2 = i;
                mn = min(mn, i2-i1);
            }
        }
        return mn;
    }
};
```
