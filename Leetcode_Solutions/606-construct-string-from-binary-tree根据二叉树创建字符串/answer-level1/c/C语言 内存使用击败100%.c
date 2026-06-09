### 解题思路
使用动态调整内存使用大小，最小化内存使用

![image.png](https://pic.leetcode-cn.com/118149f1e63035ebb56cb912f5a61c6a34731cd645c36339b59aab55b2c2d1ab-image.png)


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define RET_OK    0
#define RET_FAIL  1
#define BASE_SIZE 1024
#define LOCAL_LEN 10
struct MyString {
	char *buf;
	int size;
	int len;
};
inline int strInit(struct MyString *str)
{
	str->buf = (char*)calloc(BASE_SIZE, sizeof(char));
	if (str->buf == NULL) {
		return RET_FAIL;
	}
	str->size = BASE_SIZE;
	str->len = 0;
	return RET_OK;
}

inline int strAppend(struct MyString *str, char *astr)
{
	char *buf = NULL;
	int astrLen = strlen(astr);
	if ((str->len + astrLen) >= str->size) {
		buf = (char*)calloc(str->size + BASE_SIZE, sizeof(char));
		if (buf == NULL) {
			return RET_FAIL;
		}
		memcpy(buf, str->buf, str->len);
		free(str->buf);
		str->buf = buf;
		str->size += BASE_SIZE;
	}
	str->len += sprintf(&str->buf[str->len], "%s", astr);
	return RET_OK;
}

void trans(struct TreeNode* t, struct MyString *str, bool isRoot)
{
	char lbuf[LOCAL_LEN];
	if (t == NULL) {
		sprintf(lbuf, "()");
		strAppend(str, lbuf);
		return;
	}
	if (isRoot) {
		sprintf(lbuf, "%d", t->val);
		strAppend(str, lbuf);
	} else {
		sprintf(lbuf, "(%d", t->val);
		strAppend(str, lbuf);
	}
	if (t->left != NULL && t->right != NULL) {
		trans(t->left, str, false);
		trans(t->right, str, false);
	} else if (t->left == NULL && t->right != NULL) {
		trans(NULL, str, false);
		trans(t->right, str, false);
	} else if (t->left != NULL && t->right == NULL) {
		trans(t->left, str, false);
	}
	if (!isRoot) {
		sprintf(lbuf, ")");
		strAppend(str, lbuf);
	}
	return;
}

char * tree2str(struct TreeNode* t){
	struct MyString str = { 0 };
	if(strInit(&str) != RET_OK) {
		return NULL;
	}
	if (t != NULL) {
		trans(t, &str, true);
	}
	return str.buf;
}
```