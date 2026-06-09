### 解题思路
UTHASH

### 代码

```c
typedef struct MHashNode {
	char key;
	int lft;
	int all;
	bool beFlesh;
	UT_hash_handle hh;
} HNode;

void refleshHash (HNode *hashHead) {
	HNode *cur, *tmp;
	HASH_ITER(hh, hashHead, cur, tmp) {
		cur->lft = cur->all;
	}
}

int countCharacters(char ** words, int wordsSize, char * chars){
	int i, j, len, ret = 0;
	HNode *new, *fnd, *cur, *tmp;
	HNode *hashHead = NULL;
	bool needCount;

    if ((wordsSize == NULL) || (wordsSize == 0) || (chars == NULL) || (strlen(chars) == 0)) {
		return 0;
	}

	len = strlen(chars);
	for (i = 0; i < len; i++) {
		HASH_FIND(hh, hashHead, &chars[i], sizeof(char), fnd);
		if (fnd != NULL) {
			fnd->all ++;
		} else {
			new = (HNode *)calloc(1, sizeof(HNode));
			new->key = chars[i];
			new->all = 1;
			HASH_ADD(hh, hashHead, key, sizeof(char), new);
		}
	}

	for (i = 0; i < wordsSize; i++) {
		len = strlen(words[i]);
		refleshHash(hashHead);
		needCount = true;
		for (j = 0; j < len; j++) {
			HASH_FIND(hh, hashHead, &words[i][j], sizeof(char), fnd);
			if (fnd == NULL) {
				needCount = false;
				break;
			} else {
				if (fnd->lft <= 0) {
					needCount = false;
					break;
				}
				fnd->lft --;
			}
		}
		if (needCount) {
			ret += len;
		}
	}

    HASH_ITER(hh, hashHead, cur, tmp) {
		HASH_DEL(hashHead, cur);
		free(cur);
	}

	return ret;
}
```