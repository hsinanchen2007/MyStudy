### 解题思路

48ms是一个错误示范，会导致内存泄漏，没有释放子节点申请的内存。

```c
void trieFree(Trie* obj) {
    free(obj);
}
```

108 ms是正确的内存释放方法

```c
void trieFree(Trie* obj) {
    if (obj == NULL ) return;
    for (int i = 0; i < 26; i++){
        if (obj->next[i]){
            trieFree(obj->next[i]);
        }
    }
    free(obj);
}
```

其余看代码即可，非常简洁（其实是简陋）。


```c

typedef struct trie{
    int isEnd;
    struct trie* next[26];
    
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *root;
    root = (Trie *)malloc(sizeof(Trie) * 1 );
    memset(root, 0, sizeof(*root));
    root->isEnd = 0;
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *node = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        if ( node->next[c-'a'] == NULL){
            node->next[c-'a'] = trieCreate();
        }
        node = node->next[c-'a'];
    }
    node->isEnd = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    for (int i = 0; word[i] != '\0'; i++){
        char c = word[i];
        if ( node->next[c-'a'] == NULL){
            return false;
        }
        node = node->next[c-'a'];
    }
    return node->isEnd > 0;
  
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    for (int i = 0; prefix[i] != '\0'; i++){
        char c = prefix[i];
        if ( node->next[c-'a'] == NULL){
            return false;
        }
        node = node->next[c-'a'];
    }
    return true;
  
}

void trieFree(Trie* obj) {
    if (obj == NULL ) return;
    for (int i = 0; i < 26; i++){
        if (obj->next[i]){
            trieFree(obj->next[i]);
        }
    }
    free(obj);
}

```

另外附上Cpp的代码, 和 C语言其实差不多。

```cpp
class Trie {
    struct Node{
        int isEnd;
        Node *next[26] = {NULL};
        Node(int val ) {isEnd = val;};
    };
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(0);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for ( char c : word){
            if (node->next[c-'a'] == NULL){
                node->next[c-'a'] = new Node(0);
            }
            node = node->next[c-'a'];
        }
        node->isEnd = 1;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node = root;
        for ( char c: word){
            if (node->next[c-'a'] == NULL){
                return false;
            }
            node = node->next[c-'a'];
        }
        return node->isEnd;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * node = root;
        for ( char c: prefix){
            if (node->next[c-'a'] == NULL){
                return false;
            }
            node = node->next[c-'a'];
        }
        return true;
    }
};
```