### 解题思路

![无标题.png](https://pic.leetcode-cn.com/07e468682d3936f92d92ddd4eaffaf03f672654488ed191a53f9ce8f681f68aa-%E6%97%A0%E6%A0%87%E9%A2%98.png)

- 如图所示，单词方块每次新增一个单词，对他的要求是前缀必须是框中所选前缀，何如快速判断前缀，Trie树是不二之选；
- 剩下的就是如何全排列了，通过DFS可以实现全排列，可以通过二进制枚举法，但是题目中说明单词最多个数是500个，所以二进制枚举法不可行，只能通过DFS；
- DFS的复杂度是O(2^n)，就是要通过Trie树来剪枝；
- C语言注意三维指针和输入输出的配置；
- 题中还有个比较坑的地方是，单词可以重复利用，题目中没有明确说明，但是示例二中有体现；

### 代码

```c
#include <stdio.h>
#define MAX_N 26
#define MAX_STR_LEN 6
#define MAX_ANS 10240

struct TrieNode {
	int endCnt;
	struct TrieNode *nodes[MAX_N];
};

static struct TrieNode g_root;

static void AddNode(struct TrieNode *root, char *s)
{
	int pos, i, sLen;
	struct TrieNode *p = root;
	sLen = strlen(s);

	for (i = 0; i < sLen; i++) {
		pos = s[i] - 'a';
		if (p->nodes[pos] == NULL) {
			p->nodes[pos] = (struct TrieNode *)calloc(1, sizeof(struct TrieNode));
		}
		p = p->nodes[pos];
		if (i == sLen - 1) {
			p->endCnt++;
		}
	}
}

static bool FindStr(struct TrieNode *root, char *s)
{
	int pos, i, sLen;
	struct TrieNode *p = root;
	sLen = strlen(s);

	for (i = 0; i < sLen; i++) {
		pos = s[i] - 'a';
		if (p->nodes[pos] == NULL) {
			return false;
		}
		p = p->nodes[pos];
	}
	return true;
}

static void GenTrie(char ** words, int wordsSize)
{
	int i;

	for (i = 0; i < wordsSize; i++)	{
		AddNode(&g_root, words[i]);
	}
}

static char ***g_ans;
static int g_ansIndex;

static char g_record[MAX_STR_LEN][MAX_STR_LEN];
static int g_recordIndex;

static void GetPre(int step, char *pre)
{
	int i, j, preIndex;

	memset(pre, 0, MAX_STR_LEN);
	preIndex = 0;

	for (i = 0; i < step; i++) {
		pre[preIndex++] = g_record[i][step];
	}
}

static void CopyAns(char in[][MAX_STR_LEN], int len, char **out)
{
	int i;

	for (i = 0; i < len; i++) {
		strcpy(out[i], in[i]);
	}
}

static void Dfs(int sLen, char ** words, int wordsSize)
{
	char preStr[MAX_STR_LEN] = { 0 };
	int k, j;

	GetPre(g_recordIndex, preStr);
	if (!FindStr(&g_root, preStr)) {
		return;
	}

	/* 如果选中了sLen个单词，说明构成了方块 */
	if (g_recordIndex == sLen) {
		if (g_ansIndex >= MAX_ANS) {
			printf("%d ", g_ansIndex);
			return;
		}

		g_ans[g_ansIndex] = (char **)calloc(1, sizeof(char **) * MAX_STR_LEN);
		for (j = 0; j < MAX_STR_LEN; j++) {
			g_ans[g_ansIndex][j] = (char *)calloc(1, sizeof(char *) * MAX_STR_LEN); 
		}

		CopyAns(g_record, g_recordIndex, g_ans[g_ansIndex]);
		g_ansIndex++;
		return;
	}

	for (k = 0; k < wordsSize; k++) {
		if (strncmp(words[k], preStr, strlen(preStr)) != 0) {
			continue;
		}
		memset(g_record[g_recordIndex], 0, MAX_STR_LEN);
		strcpy(g_record[g_recordIndex], words[k]);
		g_recordIndex++;
		Dfs(sLen, words, wordsSize);
		g_recordIndex--;
	}
}

char ***wordSquares(char ** words, int wordsSize, int* returnSize, int** returnColumnSizes)
{
	int sLen = strlen(words[0]);
	int i, j;

	g_ans = (char ***)calloc(1, sizeof(char ***) * MAX_ANS);

	memset(&g_root, 0, sizeof(g_root));
	memset(g_record, 0, sizeof(g_record));

	g_ansIndex = 0;
	g_recordIndex = 0;

	GenTrie(words, wordsSize);
	Dfs(sLen, words, wordsSize);
	*returnSize = g_ansIndex;
	*returnColumnSizes = (int *)calloc(1, sizeof(int) * g_ansIndex);
	for (i = 0; i < g_ansIndex; i++) {
		(*returnColumnSizes)[i] = sLen;
	}
	return g_ans;
}
```