### 解题思路
UThash 吧  C语言太难了

### 代码

```c
#define DEBUG
#ifdef DEBUG
#define logi(...) printf(__VA_ARGS__)
#else
#define logi(...)
#endif

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize) {
	typedef struct _key_info_t {
		char word_len[20];
	} key_info_t;
	typedef struct _my_hash_t {
		key_info_t key;
		int id;
		int count;
		UT_hash_handle hh;
	} my_hash_t;
	my_hash_t *g_user = NULL;

	int i, j = 0;
	int max_count = 0;
	char temp_word[20] = { 0 };
	char *p = NULL;
	while (paragraph[i] != '\0') {
		if (isalpha(paragraph[i])) {
			if (isupper(paragraph[i])) {
				paragraph[i] = tolower(paragraph[i]);
			}
			temp_word[j++] = paragraph[i];
		}
		else {
			if (j != 0) {
				my_hash_t *h = NULL;
				HASH_FIND(hh, g_user, temp_word, sizeof(key_info_t), h);
				if (h == NULL) {
					h = (my_hash_t*)malloc(sizeof(my_hash_t));
					memset(h, 0, sizeof(key_info_t));
					memcpy(h->key.word_len, temp_word, sizeof(char)*(20));
					h->count = 1;
					HASH_ADD(hh, g_user, key, sizeof(key_info_t), h);
				}
				else {
					h->count++;
				}
				memset(temp_word, 0, 20 * sizeof(char));
				j = 0;
			}
		}
		i++;
	}

	if (j != 0) {
		my_hash_t *h = NULL;
		HASH_FIND(hh, g_user, temp_word, sizeof(key_info_t), h);
		if (h == NULL) {
			h = (my_hash_t*)malloc(sizeof(my_hash_t));
			memset(h, 0, sizeof(key_info_t));
			memcpy(h->key.word_len, temp_word, sizeof(char)*(20));
			h->count = 1;
			HASH_ADD(hh, g_user, key, sizeof(key_info_t), h);
		}
		else {
			h->count++;
		}
		memset(temp_word, 0, 20 * sizeof(char));
		j = 0;
	}

	for (i = 0; i<bannedSize; i++) {
		key_info_t curr_key; // 构建禁用单词的key值
		memset(&curr_key, 0, sizeof(key_info_t));
		memcpy(curr_key.word_len, banned[i], strlen(banned[i]) * sizeof(char));
		my_hash_t *s = NULL;
		HASH_FIND(hh, g_user, &curr_key, sizeof(key_info_t), s); // 在hash表中查找key
		if (s != NULL) {
			s->count = 0;
		}
	}
	my_hash_t *ss, *tmp = NULL;
	my_hash_t *max_node = NULL;

	HASH_ITER(hh, g_user, ss, tmp) {
		if (max_count < ss->count) {
			max_count = ss->count;
			max_node = ss;
		}
	}
	return max_node->key.word_len;
}
```