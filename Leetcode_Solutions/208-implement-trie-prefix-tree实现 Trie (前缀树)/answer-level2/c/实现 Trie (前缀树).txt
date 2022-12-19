### 解题思路
前缀树的C实现
### 代码

```c
typedef struct {
	struct Trie* children[26];
	bool isEnd;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
	Trie* trie = (Trie*)malloc(sizeof(Trie));
	for (int i = 0; i < 26; i++) {
		trie->children[i] = NULL;
	}
	trie->isEnd = false;
	return trie;
}
Trie* get(Trie* node, char c) {
	if (node->children[c - 'a'] == NULL) {
		node->children[c - 'a'] = trieCreate();
	}
	return node->children[c-'a'];
}
/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
	if (!obj || !word || !strlen(word)) return;
	Trie* cur = obj;
	for (int i = 0; i < strlen(word); i++) {
		cur = get(cur, word[i]);
	}
	cur->isEnd = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
	if (!obj) return false;
	Trie* cur = obj;
	for (int i = 0; i < strlen(word); i++) {
		if (cur->children[word[i] - 'a'] == NULL) {
			return false;
		}
		else {
			cur = cur->children[word[i]-'a'];
		}
	}
	return cur->isEnd;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
	Trie* cur = obj;
	for (int i = 0; i < strlen(prefix); i++) {
		if (cur->children[prefix[i] - 'a'] == NULL) {
			return false;
		}
		else {
			cur = cur->children[prefix[i] - 'a'];
		}
	}
	return true;
}

void trieFree(Trie* obj) {
	if (!obj) return;
	for (int i = 0; i < 26; i++)
	{
		if (obj->children[i] != NULL) {
			trieFree(obj->children[i]);
		}
	}
	free(obj);
}
```