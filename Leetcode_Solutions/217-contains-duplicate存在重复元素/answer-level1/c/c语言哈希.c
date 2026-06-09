### 解题思路
此处撰写解题思路

### 代码

```c
struct hash_data{
	int key;
	struct hash_data * next;
};

struct hash_table
{
	struct hash_data ** head; //数组
	int hash_width;
};

///初始化
int hash_init(struct hash_table * table, int width){
	if(width<=0)
		return -1;
	struct hash_data **tmp = (struct hash_data **)malloc(sizeof(struct hash_data *)*width);
	table->head = tmp;
	memset(table->head, 0, width * sizeof(struct hash_data *));
	if(table->head==NULL)
		return -1;
	table->hash_width = width;
	return 0;
}

///释放
void hash_free(struct hash_table table){
	if(table.head!=NULL){
		for (int i=0; i<table.hash_width; i++) {
			struct hash_data* element_head= table.head[i];
			while (element_head !=NULL) {
				struct hash_data* temp =element_head;
				element_head = element_head->next;
				free(temp);
			}
		}
		free(table.head);
		table.head = NULL;
	}
	table.hash_width = 0;
}

int hash_addr(struct hash_table table,int key){
	int addr =abs(key) % table.hash_width;
	return addr;
}

///增加
int hash_insert(struct hash_table table,int key){
	struct hash_data * tmp = (struct hash_data *)malloc(sizeof(struct hash_data));
	if(tmp == NULL)
		return -1;
	tmp->key = key;
	int k = hash_addr(table,key);
	tmp->next =table.head[k];
	table.head[k]=tmp;
	return 0;
}

///查找
struct hash_data* hash_find(struct hash_table table, int key){
	int k = hash_addr(table,key);
	struct hash_data* element_head=table.head[k];
	while (element_head !=NULL) {
		if ( element_head->key == key) {
			return element_head;
		}
		element_head = element_head->next;
	}
	return NULL;
}


bool containsDuplicate(int* nums, int numsSize){
	struct hash_table table;
    bool ret = false;
	hash_init(&table, 100);
	for(int i = 0; i < numsSize; i++){
		struct hash_data* data=  hash_find(table, nums[i]);
		if (data !=NULL) {
			ret = true;
			break;
		}
		hash_insert(table,nums[i]);
	}
	hash_free(table);
	return ret;
}
```