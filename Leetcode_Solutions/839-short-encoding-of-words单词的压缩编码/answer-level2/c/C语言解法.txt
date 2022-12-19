### 解题思路
灵感来自于甜姨，需要注意的是排序的时候，利用qsort就可以，不需要自己单独写。Trie树的题目，可以先做 208. 实现 Trie (前缀树)

### 代码

```c
#define MAX_CHILD 26
typedef struct trie {
    struct trie *child[MAX_CHILD];
} Trie;

Trie* trieCreate() {
    Trie *tree = (Trie*)malloc(sizeof(Trie));
    if (tree == NULL) {
        return NULL;
    }
    memset(tree, 0, sizeof(Trie));
    return tree;
}

int Compare(const void *a, const void *b)
{
    //printf("%s %s\n", *(char**)a, *(char**)b);
	return strlen(*(char**)b) - strlen(*(char**)a);
}

int TrieInsert(Trie* obj, char *word) {
	if (obj == NULL || word == NULL) {
		return 0;
	}
	
	bool isNew = 0;
	for (int i = strlen(word) - 1; i >= 0; i--) {
		if (obj->child[word[i] - 'a'] == NULL) {
			isNew = 1;
			obj->child[word[i] - 'a'] = trieCreate();
		}
		obj = obj->child[word[i] - 'a'];
	}
	 return isNew ? (strlen(word) + 1) : 0;
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
	if (words == NULL) {
		return 0;
	}
	qsort(words, wordsSize, sizeof(words[0]), Compare);
	
    int len = 0;
	Trie *tree = trieCreate();
	if (tree == NULL) {
		return 0;
	}
    
	for (int i = 0; i < wordsSize; i++) {
		len += TrieInsert(tree, words[i]);
	}

    return len;
}
```