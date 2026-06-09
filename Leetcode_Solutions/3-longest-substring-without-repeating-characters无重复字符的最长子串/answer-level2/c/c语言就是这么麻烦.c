### 解题思路
此处撰写解题思路

### 代码

```c
struct hashData{
	int key;
	struct hashData *next;
};

struct hashTable{
	struct hashData **table;
	int hashWide;
};

struct hashData *hash_find(struct hashTable *table, int key)
{
	int index; 
	struct hashData *data;

	if(table == NULL){
		return NULL;
	}

	index = abs(key) % table->hashWide;
	data = table->table[index];
	while(data != NULL){
		if(data->key == key){
			return data;
		}
		data = data->next;
	}

	return NULL;
}

int hash_insert(struct hashTable *table, int key)
{
	int index;
	struct hashData *data = NULL;
	if(table == NULL){
		return -1;
	}

	data = (struct hashData *)malloc(sizeof(struct hashData));
	index = abs(key) % table->hashWide;
	data->key = key;
	data->next = table->table[index];
	table->table[index] = data;

	return 0;
}

int hash_init(struct hashTable *table, int wide)
{
	struct hashData **head = NULL;

	if(table == NULL || wide <= 0){
		return -1;
	}

	head = (struct hashData **)malloc(sizeof(struct hashData *)*wide);
	if(head == NULL){
		return -1;
	}
	memset(head, 0, sizeof(struct hashData *)*wide);
	table->table = head;
	table->hashWide = wide;

	return 0;
}

int hash_free(struct hashTable *table)
{
	int i;

	if(table == NULL){
		return -1;
	}

	for(i = 0; i < table->hashWide; i++){
		struct hashData *data = table->table[i];
		while(data != NULL){
			struct hashData *temp = data;
			data = data->next;
			temp->next = NULL;
			free(temp);
		}
	}
	memset(table->table, 0, sizeof(struct hashData *)*(table->hashWide));

	return 0;
}

int hash_destroy(struct hashTable *table)
{
	if(table == NULL){
		return -1;
	}

	free(table->table);
	table->hashWide = 0;

	return 0;
}

int lengthOfLongestSubstring(char * s){
	int ret, length, len, maxlen, i, y;
	struct hashTable table;
	struct hashData *data = NULL;

	ret = hash_init(&table, 128);
	if(ret < 0){
		return -1;
	}

	maxlen = 0;
	length = strlen(s);
	for(i = 0; i < length; i++){
		len = 0;
		for(y = i; y < length; y++){
			data = hash_find(&table, s[y]);
			if(data == NULL){
				hash_insert(&table, s[y]);
				len++;
				continue;
			}

			hash_free(&table);
			break;
		}
		if(len > maxlen){
			maxlen = len;
		}
	}

	hash_destroy(&table);

	return maxlen;
}
```