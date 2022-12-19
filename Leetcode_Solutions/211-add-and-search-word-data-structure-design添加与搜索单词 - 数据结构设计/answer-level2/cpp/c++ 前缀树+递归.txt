```
class WordDictionary {
    bool isEnd=false;
    WordDictionary *next[26];
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        memset(next,0,sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p=this;
        for(auto w:word){
            if(p->next[w-'a']==NULL)p->next[w-'a']=new WordDictionary();
            p=p->next[w-'a'];
        }
        p->isEnd=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word,0,this);
    }
    bool search(string &word,int start, WordDictionary *w) {
        auto p=w;
        for(int i=start;i<word.size();++i){
            char w=word[i];
            if(w=='.'){
                for(int j=0;j<26;++j)
                    if(p->next[j]!=NULL&&search(word,i+1,p->next[j]))return true;
                return false;
            }else{
                if(p->next[w-'a']==NULL)return false;
                p=p->next[w-'a'];
            } 
        }
        return p->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
