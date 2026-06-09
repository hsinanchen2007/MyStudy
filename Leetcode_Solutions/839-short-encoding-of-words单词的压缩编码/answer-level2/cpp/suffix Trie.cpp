```c++
struct TrieNode{
    bool isWord;
    string word;
    int length;
    struct TrieNode * next[26];
    TrieNode(){
        this->isWord = false;
        this->length = 0;
        for(int i = 0; i < 26; ++i){
            this->next[i] = NULL;
        }
    }
};

bool insertTrie(TrieNode * root,string & word){
    if(!root) return false;
    TrieNode * node = root;
    for(auto c : word){
        if(!node->next[c-'a']) node->next[c-'a'] = new TrieNode();
        node = node->next[c-'a'];
    }
    node->isWord = true;
    node->length = word.size();
    node->word = word;
    return true;
}

bool searchTrie(TrieNode * root,vector<string> & res){
    if(!root) return false;
    bool isleaf = true;

    for(int i = 0; i < 26; ++i){
        if(root->next[i]){
            isleaf = false;
            break;
        }
    }

    if(isleaf){
        if(root->isWord){
            res.push_back(root->word);
        }
    }else{
        for(int i = 0; i < 26; ++i){
            if(root->next[i]){
                searchTrie(root->next[i],res);
            }
        }
    }

    return true;
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        vector<string> keys;

        TrieNode * root = new TrieNode();
        for(auto & word : words){
            reverse(word.begin(),word.end());
            insertTrie(root,word);
        }
        searchTrie(root,keys);
        for(int i = 0; i < keys.size(); ++i){
            res += keys[i].size();
        }
        res += keys.size();

        return res;
    }
};
```