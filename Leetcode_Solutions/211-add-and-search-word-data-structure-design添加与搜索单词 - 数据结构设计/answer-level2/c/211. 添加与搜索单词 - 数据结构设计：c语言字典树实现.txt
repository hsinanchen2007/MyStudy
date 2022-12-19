
typedef struct _node_t{
    bool is_end;
    char ch;
    struct _node_t * next[26];
}node_t;

typedef struct {
    node_t head;
} WordDictionary;
void init_node(node_t *node){
    int i = 0;
    node->is_end = false;
    node->ch = '\0';
    for(i = 0; i<26; i++){
        node->next[i] = NULL;
    }
}
void add_node(node_t *node, char *word){
    if(*word == '\0'){
        node->is_end = true;
    } else if(node->next[*word - 'a'] != NULL){
        add_node(node->next[*word - 'a'], word + 1);
    } else {
        node_t *node_tmp = (node_t *)malloc(sizeof(node_t));
        init_node(node_tmp);
        node_tmp->ch = *word;
        if(*(word + 1) == '\0'){
            node_tmp->is_end = true;
        }
        node->next[*word - 'a'] = node_tmp;
        add_node(node_tmp, word + 1);
    }
}
bool search_node(node_t *node, char *word){
    int i = 0;
    if(node == NULL){
        return false;
    }

    if(*word == '.'){
        for(i = 0; i<26; i++){
            if(search_node(node->next[i], (word + 1))){
                return true;
            }
        }
        return false;
    } else if(*word == '\0') {
        if(node->is_end){
            return true;
        }
        else{
            return false;
        }
    } else if(*word >= 'a' && *word <= 'z'){
        if(search_node(node->next[*word - 'a'], (word + 1))){
            return true;
        } else {
            return false;
        }
    }
    return true;
}
/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary *p_dic = (WordDictionary *)malloc(sizeof(WordDictionary));
    init_node(&p_dic->head);
    p_dic->head.is_end = true;
    return p_dic;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    add_node(&obj->head, word);
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    return search_node(&obj->head, word);
}

void wordDictionaryFree(WordDictionary* obj) {
    
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/