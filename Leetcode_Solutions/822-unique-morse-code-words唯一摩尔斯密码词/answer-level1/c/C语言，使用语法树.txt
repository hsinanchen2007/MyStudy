```
#define RET_OK	0
#define RET_ERR	1

#define BUF_SIZE	(12*4+1)
#define MOSI_CNT	26
struct MyTreeNode {
	char val;
	unsigned char end;
	struct MyTreeNode *left;
	struct MyTreeNode *right;
};
void addNode(struct MyTreeNode *node, char *mosiStr, int cur, int len)
{
	struct MyTreeNode **lNode = NULL;
	lNode = mosiStr[cur] == '-' ? &(node->left) : (&node->right);
	if (*lNode == NULL) {
		*lNode = (struct MyTreeNode *)calloc(1, sizeof(struct MyTreeNode));
		if (*lNode == NULL) {
			return;
		}
		(*lNode)->val = mosiStr[cur];
	}
	if ((cur + 1)  == len) {
		(*lNode)->end = 1;
		return;
	}
	addNode(*lNode, mosiStr, cur + 1, len);
	return;
}
void totalLeaf(struct MyTreeNode *node, int *cnt)
{
	if (node->end == 1) {
		*cnt = *cnt + 1;
	}
	if (node->left != NULL) {
		totalLeaf(node->left, cnt);
	}
	if (node->right != NULL) {
		totalLeaf(node->right, cnt);
	}
}
void freeTree(struct MyTreeNode *node)
{
	if (node == NULL) {
		return;
	}
	if (node->left != NULL) {
		freeTree(node->left);
		free(node->left);
		node->left = NULL;
	}
	if (node->right != NULL) {
		freeTree(node->right);
		free(node->right);
		node->right = NULL;
	}
}
const char* mosi[MOSI_CNT] = {
	".-","-...","-.-.","-..",".","..-.","--.",
	"....","..",".---","-.-",".-..","--","-.",
	"---",".--.","--.-",".-.","...","-",
	"..-","...-",".--","-..-","-.--","--.."
};
const int mosiLen[MOSI_CNT] = {
	2, 4, 4, 3, 1, 4, 3, 
	4, 2, 4, 3, 4, 2, 2, 
	3, 4, 4, 3, 3, 1, 
	3, 4, 3, 4, 4, 4, 
};
int transWord(char *word, int wordLen, char *buf, int bufSize)
{
	int i, j;
	int inx;
	for (i = 0, j = 0; i < wordLen; i++) {
		inx = word[i] - 'a';
		memcpy(&buf[j], mosi[inx], mosiLen[inx]);
		j += mosiLen[inx];
	}
	return RET_OK;
}
int uniqueMorseRepresentations(char ** words, int wordsSize){
	int i, cnt = 0;
	char buf[BUF_SIZE];
	struct MyTreeNode head = { 0 };
	if (wordsSize == 0) {
		return 0;
	}
	for (i = 0; i < wordsSize; i++) {
		memset(buf, 0, BUF_SIZE);
		transWord(words[i], strlen(words[i]), buf, BUF_SIZE);
		addNode(&head, buf, 0, strlen(buf));
	}
	totalLeaf(&head, &cnt);
	freeTree(&head);
	return cnt;
}
```