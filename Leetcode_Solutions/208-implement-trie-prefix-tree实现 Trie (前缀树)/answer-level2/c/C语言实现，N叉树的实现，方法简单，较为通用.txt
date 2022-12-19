### 解题思路
C语言实现，N叉树的实现，方法简单，较为通用

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHILD 32

typedef struct trie {
	struct trie *child[32];
	int end;
} Trie;

/** Initialize your data structure here. */

Trie *trieCreate()
{
	struct trie *t = malloc(sizeof(*t));
	memset(t, 0, sizeof(*t));
	return t;
}

/** Inserts a word into the trie. */
void trieInsert(Trie *obj, char *word)
{
	int loop;
	struct trie *node;
	if (!obj || !word)
		return;
	for (loop = 0; loop < strlen(word); loop++) {
		if (!obj->child[word[loop] - 'a']) {
			node = trieCreate();
			obj->child[word[loop] - 'a'] = node;
		}
		obj = obj->child[word[loop] - 'a'];
	}
	obj->end = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie *obj, char *word)
{
	int loop;
	if (!obj || !word)
		return false;

	for (loop = 0; loop < strlen(word); loop++) {
		if (obj->child[word[loop] - 'a']) {
			obj = obj->child[word[loop] - 'a'];
		} else {
			return false;
		}
	}
	if (obj->end)
		return true;
	return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie *obj, char *prefix)
{
	int loop;
	if (!obj || !prefix)
		return false;

	for (loop = 0; loop < strlen(prefix); loop++) {
		if (obj->child[prefix[loop] - 'a']) {
			obj = obj->child[prefix[loop] - 'a'];
		} else {
			return false;
		}
	}
	return true;
}

void trieFree(Trie *obj)
{
	int loop;
	if (!obj)
		return;
	for (loop = 0; loop < MAX_CHILD; loop++) {
		if (obj->child[loop]) {
			trieFree(obj->child[loop]);
		}
	}
	free(obj);
}
```