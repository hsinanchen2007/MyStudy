### 解题思路
1.前缀树思路构建，插入
2.为了能够实现search的功能(给定单词和词典单词只差一个字母)，我们需要先建立查看词典单词功能(即给出一个单词看此单词是否在词典中)；参考注释；

### 代码

```c
typedef struct node{
    struct node *next[26];
    bool isEnd;
} MagicDictionary;

/** Initialize your data structure here. */

MagicDictionary* magicDictionaryCreate() {
    MagicDictionary *root;
    root = (MagicDictionary*)malloc(sizeof(MagicDictionary));
    for (int i=0;i<26;i++)
        root->next[i] = NULL;
    root->isEnd = false;
    return root;
}

/** Build a dictionary through a list of words */
void magicDictionaryBuildDict(MagicDictionary* obj, char ** dict, int dictSize) {
    MagicDictionary *temp,*p;
    for (int i=0;i<dictSize;i++){
        p = obj;
        for (int j=0;dict[i][j];j++){
            if (!p->next[dict[i][j]-'a']){
                temp = (MagicDictionary*)malloc(sizeof(MagicDictionary));
                for (int k=0;k<26;k++)
                    temp->next[k] = NULL;
                temp->isEnd = false;
                p->next[dict[i][j]-'a'] = temp;
            }
            p = p->next[dict[i][j]-'a'];
        }
        p->isEnd = true;
    }
}

bool check_word(MagicDictionary *obj,char *word){
    MagicDictionary *p;
    p = obj;
    for (int i=0;word[i];i++){
        if (!p->next[word[i]-'a'])
            return false;
        p = p->next[word[i]-'a'];
    }
    return p->isEnd;
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool magicDictionarySearch(MagicDictionary* obj, char * word) {
    MagicDictionary *p;
    p = obj;
    for (int i=0;word[i];i++){
        for (int j=0;j<26;j++){
            if (p->next[j]&&j!=word[i]-'a'){
                if (check_word(p->next[j],word+i+1))
                    return true;
            }
        }//循环的目的是看除了这个字符，有其他字符也可以达到相同效果
        if (p->next[word[i]-'a'])
            p = p->next[word[i]-'a'];
        else
            break;
    }
    return false;
}

void magicDictionaryFree(MagicDictionary* obj) {
    if (!obj)   
        return;
    for (int i=0;i<26;i++){
        if (obj->next[i])
            magicDictionaryFree(obj->next[i]);
    }
    free(obj);
}

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dict, dictSize);
 
 * bool param_2 = magicDictionarySearch(obj, word);
 
 * magicDictionaryFree(obj);
*/
```