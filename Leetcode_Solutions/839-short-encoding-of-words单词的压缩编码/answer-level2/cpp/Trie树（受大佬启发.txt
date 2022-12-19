### 解题思路
此处撰写解题思路

### 代码

```cpp
class Trie
{
    bool isNew;
    Trie* children[26];
public:
    Trie()
    {
        isNew = false;
        memset(children, 0, sizeof(children));
    }

    bool insert(string word)
    {
        isNew = false;
        Trie* node = this;
        for(int i = word.length()-1; i >= 0; --i)
        {
            if(node->children[word[i]-'a'] == NULL)
            {
                node->children[word[i]-'a'] = new Trie();
                isNew = true;
                //break;
            }
            node = node->children[word[i]-'a'];
        }
        return isNew;
    }
};

class Solution {
    Trie* temp;
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){return a.length() > b.length();});
        int count = 0;
        temp = new Trie();
        for(auto word : words)
        {
            count += temp->insert(word) ? (word.length()+1) : 0;
        }

        return count;
    }
};


```