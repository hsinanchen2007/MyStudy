```
struct TrieNode{
    TrieNode * next[26];
    int len;
    bool isWord;
    TrieNode(){
        for(int i = 0;i < 26; ++i){
            this->next[i] = NULL;
        }
        this->len = 0;
        this->isWord = false;
    }
};

bool insertTrie(TrieNode * root,string & word){
    TrieNode * node = root;
    
    for(auto c : word){
        if(node->next[c-'a'] == NULL){
            node->next[c-'a'] = new TrieNode();
        }
        node = node->next[c-'a'];
    }
    node->isWord = true;
    node->len = word.size();
    
    return true;
}

vector<int> search(TrieNode * root,string & word){
    vector<int> ans;
    TrieNode * node = root;
    
    for(auto c : word){
        if(node->next[c-'a'] == NULL){
            return ans;
        }
        node = node->next[c-'a'];
        if(node->isWord){
            ans.push_back(node->len);
        }
    }
    
    return ans;
}

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        TrieNode * root = new TrieNode();
        
        for(auto w : words){
            insertTrie(root,w);
        }
        
        for(int i = 0;i < text.size(); ++i){
            string curr = text.substr(i);
            vector<int> now =  search(root,curr);
            vector<int> intervel(2,0);
            for(auto n : now){
                intervel[0] = i;
                intervel[1] = i + n - 1;
                ans.push_back(intervel);
            }
        }
        
        return ans;
    }
};
```