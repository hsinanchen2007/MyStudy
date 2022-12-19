### 代码

```cpp
class TrieNode{
public:
    TrieNode(int dep): childrenNum(0), depth(dep)
    {
        for(auto& child : children) child = nullptr;
    }
    TrieNode* get(char c)
    {
        if(!children[c - 'a'])
        {
            children[c - 'a'] = new TrieNode(depth+1);
            childrenNum ++;
        }
        return children[c - 'a'];
    }
    int countLength()
    {
        return childrenNum == 0 ? depth+1 : 0;
    }
private:
    TrieNode* children[26];
    int childrenNum;
    int depth;
};

class Solution {
public:
    //反转排序解法
    int reverseEncoding(vector<string>& words)
    {
        int ans = 0;
        for(auto& s: words) reverse(s.begin(),s.end());
        sort(words.begin(), words.end());
        for(int i = 0; i < words.size() - 1; i++)
            if(words[i] != words[i+1].substr(0, words[i].size())) ans += words[i].size() + 1;
        return ans + words[words.size()-1].size() + 1;
    }
    //字典树解法
    int dictionaryEncoding(vector<string>& words)
    {
        TrieNode* dict = new TrieNode(0);
        unordered_set<TrieNode*> leafs;
        int ans = 0;
        for(auto& s : words)
        {
            TrieNode* cur = dict;
            for(int i = s.length() - 1; i >= 0; i--)
                cur = cur->get(s[i]);
            leafs.insert(cur);
        }
        for(auto leaf : leafs) ans += leaf->countLength();
        return ans;
    }

    int minimumLengthEncoding(vector<string>& words) {
        //反转排序解法
        return reverseEncoding(words);

        //字典树解法
        // return dictionaryEncoding(words);
    }
};
```