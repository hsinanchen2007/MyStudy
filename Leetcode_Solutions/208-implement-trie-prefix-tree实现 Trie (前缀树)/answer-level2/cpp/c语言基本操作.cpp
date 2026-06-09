```
#define maxn 26
#define nullptr NULL
struct TrieNode{
    bool isStr;
    struct TrieNode*next[maxn];
};

typedef struct TrieNode Trie;
/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* root=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<maxn;i++)
        root->next[i]=nullptr;

    root->isStr=false;
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
  
    if(obj==nullptr||*word=='\0')
        return ;
    Trie* p=obj;
    while(*word!='\0'){
       if(p->next[*word-'a']==nullptr)
       {
         Trie* temp=trieCreate();
          p->next[*word-'a']=temp;
          p=p->next[*word-'a'];
       }
       else
        p=p->next[*word-'a'];
    word++;
  }
  p->isStr=true;
}
/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
   if(obj==nullptr) return false;
    Trie* p=obj;
    while(*word!='\0')
    {
        if(p->next[*word-'a']==nullptr)
           return false;
        p=p->next[*word-'a']; 
        word++;
    }
    return  p->isStr;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    
    Trie* p=obj;
    while(*prefix!='\0')
    {
        if(p->next[*prefix-'a']!=nullptr)
          p=p->next[*prefix-'a'];
        else
          return false;
        prefix++;
    }     
    return true;
}

void trieFree(Trie* obj) {
    if(obj==nullptr)
      return ;
    for(int i=0;i<maxn;i++)
    {
        if(obj->next[i]!=nullptr)
      trieFree(obj->next[i]);    
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
```
