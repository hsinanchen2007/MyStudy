解题思路：构建字典树，插入所有词根，为了方便，可以将词根对应的dict下标也放在节点里。遍历sentence中的每一个单词，如果能在字典树中找到其前缀则进行替换，否则不变，具体见代码

```
class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    int idx;
    TrieNode(){
        for(int i=0; i<26; i++)
            children[i] = NULL;
        isWord = false;
        idx = -1;
    }
};

class TrieTree{
public:
    TrieNode* root;
    TrieTree(){
        root = new TrieNode();
    }

    void insert(string s, int i){
        TrieNode* cur = root;
        for(char c: s){
            if(cur->children[c-'a']==NULL)
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
        cur->idx = i;
    }

    int search(string s){
        TrieNode* cur = root;
        for(char c:s){
            if(cur->children[c-'a']==NULL)
                return -1;
            else{
                if(cur->children[c-'a']->isWord){
                    return  cur->children[c-'a']->idx;
                }
            }
            cur = cur->children[c-'a'];
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieTree* tree = new TrieTree();
        for(int i=0; i<dict.size(); i++)
            tree->insert(dict[i], i);
        string ans = "";
        for(int i=0, iStart=0; i<sentence.length(); i++){
            if(sentence[i]==' '){
                string word = sentence.substr(iStart, i-iStart);
                iStart = i+1;
                int t = tree->search(word);
                if(t==-1)
                    ans += word + " ";
                else
                    ans += dict[t] + " ";
            }
            if(i==sentence.length()-1){
                string word = sentence.substr(iStart, i-iStart+1);
                int t = tree->search(word);
                if(t==-1)
                    ans += word;
                else
                    ans += dict[t];
            }
        }
        return ans;
    }
};
```
