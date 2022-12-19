### 解题思路
1、DFS将所有二叉树的子树都展开为string。
2、用string做为Hash key，TreeNode做为Hash data。
3、输出Hash中重复项。

备注：用C求解有一处困难点，展开为string的时候到底分配多大的内存好.....

### 代码

```c
#define MAX_STRING_LEN 20000
#define DEBUG 

typedef struct {
    char* key;
    struct TreeNode* data;
    int cnt;
    UT_hash_handle hh;
} Hash;

void AddHash(char* key, struct TreeNode* data, Hash** hashObj)
{
    Hash* node;
    HASH_FIND_STR(*hashObj, key, node);
    if (node == NULL) {
        Hash* tmp = calloc(1, sizeof(Hash));
        tmp->key = key;
        tmp->data = data;
        tmp->cnt++;
        HASH_ADD_KEYPTR(hh, *hashObj, key, strlen(key), tmp);
        DEBUG("%s is first record\n", key);
    } else {
        node->cnt++;
        DEBUG("%s is repeat\n", key);
    }
}

void DelHash(Hash** hashObj)
{
    Hash* node;
    Hash* node2;
    HASH_ITER(hh, *hashObj, node, node2) {
        HASH_DEL(*hashObj, node);
        free(node->key);
        free(node);
    }
}

void OutPut(Hash** hashObj, struct TreeNode** recordData, int* returnSize)
{
    Hash* node;
    Hash* node2;
    HASH_ITER(hh, *hashObj, node, node2) {
        if (node->cnt > 1) {
            recordData[*returnSize] = node->data;
            DEBUG("Tree[%d] = %d\n", *returnSize, node->data->val);
            (*returnSize)++;
        }
    }
}

char* Dfs(struct TreeNode* root, Hash** hashObj)
{
    if (root == NULL) {
        return "#";
    }

    char* string = calloc(MAX_STRING_LEN, sizeof(char));
    sprintf(string, "%d ", root->val);
    strcat(string, Dfs(root->left, hashObj));
    strcat(string, Dfs(root->right, hashObj));

    AddHash(string, root, hashObj);
    return string;
# }

struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize)
{
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	
    Hash* hashObj = NULL;
	Dfs(root, &hashObj);
	
    *returnSize = 0;
    struct TreeNode** recordData = calloc(HASH_COUNT(hashObj), sizeof(struct TreeNode*));
    OutPut(&hashObj, recordData, returnSize);

    DelHash(&hashObj);
	return recordData;
}
```