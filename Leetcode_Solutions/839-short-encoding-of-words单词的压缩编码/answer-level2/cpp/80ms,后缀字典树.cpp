```
struct Trie{
    Trie* child[26];
    bool t;
    Trie(){
        for(int i = 0; i < 26; ++i){
            child[i] = NULL;
        }
        t = false;
    }
    Trie* get(char& x){
        if(child[x-'a'] == NULL){
            child[x-'a'] = new Trie();
            t = true;
        }
        return child[x-'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size(), sum = 0;
        Trie* res = new Trie();
        unordered_map<Trie*,int> m;
        for(int i = 0; i < len; ++i){
            Trie* temp = res;
            for(int j = words[i].size()-1; j >= 0; --j){
                temp = temp->get(words[i][j]);
            }
            if(temp->t == false){
                m[temp] = i;
            }
        }
        for(auto p:m){
            if(p.first->t == false){
                sum += words[p.second].size()+1;
            }
        }
        return sum;
    }
};
```
