### 解题思路
此处撰写解题思路

### 代码

```c

/*
给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

示例 1:

输入: "bcabc"
输出: "abc"
解释: 原字符串中 ‘b’, ‘c’ 均有多个，在不改变原有字符位置前提下，去掉最前面的 “bc”，使得输出字符串字典序最小
示例 2:

输入: "cbacdcbc"
输出: "acdb"

"cbbbcaa"
"abacb"

*/

struct StackNode {
	int pos;
	int cnt;
	struct StackNode *next;
};

int StackPush(struct StackNode *head, int pos)
{
	struct StackNode *temp = (struct StackNode *)malloc(sizeof(struct StackNode));
	temp->pos = pos;
	temp->next = head->next;
	head->next = temp;
	head->cnt++;
	printf("Push %c cnt %d \n", (char)pos, head->cnt);
	return 0;
}

int StackPop(struct StackNode *head)
{
	struct StackNode *temp = head->next;
	head->next = temp->next;
	head->cnt--;
	int ret = temp->pos;
	free(temp);
	printf("Pop %c cnt %d \n", (char)ret, head->cnt);
	return ret;
}

int StackEmpty(struct StackNode *head)
{
	int ret = head->next != NULL ? 0 : 1;
	return ret;
}

struct HashSet {
	int cKey; /* key */
	int cnt;
	UT_hash_handle hh; /* makes this structure hashable */
};

struct HashSet *g_hashHead = NULL;

void addUser(int myKey)
{
	struct HashSet *temp = NULL;

	HASH_FIND_INT(g_hashHead, &myKey, temp);
	if (temp == NULL) {
		temp = (struct HashSet *)malloc(sizeof(struct HashSet));
		temp->cKey = myKey;
		temp->cnt= 1;
		HASH_ADD_INT(g_hashHead, cKey, temp);
	}
}

char* removeDuplicateLetters(char* s)
{
	int flag[26];
	int fI[26];
	int i;
	int len = strlen(s);
	for (i = 0; i < 26; i++) {
		flag[i] = 0;
		fI[i] = 0;
	}
	for (i = 0; i < len; i++) {
		flag[s[i] - 'a']++;
	}

	struct StackNode *headNode = (struct StackNode *)malloc(sizeof(struct StackNode));
	headNode->pos = -1;
	headNode->cnt = 0;
	headNode->next = NULL;

	int temp;
	struct StackNode *topNode = NULL;
	for (i = 0; i < len; i++) {
		printf("i %d s %c \n", i, s[i]);
		while (StackEmpty(headNode) != 1) {
			topNode = headNode->next;
			printf("top %c \n", (char)(topNode->pos));
			temp = topNode->pos - 'a';
			if (topNode->pos > s[i] && flag[temp] > 1 && fI[s[i] - 'a'] < 1) {
				StackPop(headNode);
				flag[temp]--;
				fI[temp]--;
			} else {
				break;
			}
		}
		if (fI[s[i] - 'a'] < 1) {
			StackPush(headNode, s[i]);
			fI[s[i] - 'a']++;
		} else {
			flag[s[i] - 'a']--;
		}
	}

/*
	//不需要再去删除，因为前面只入栈一次。
	struct StackNode *preNode = headNode;
	struct StackNode *tmpNode = headNode->next;
	while (tmpNode != NULL) {
		printf("pre %c tmp %c \n", preNode->pos, tmpNode->pos);
		temp = tmpNode->pos - 'a';
		printf("flag %d temp %d \n", flag[temp], temp);
		if (flag[temp] > 1) {
			preNode->next = tmpNode->next;
			tmpNode = preNode->next;
			headNode->cnt--;
			flag[temp]--;
			printf("del temp %c \n", temp + 'a');
		} else {
			preNode = preNode->next;
			tmpNode = tmpNode->next;
		}

	}
*/

	char *ans = (char *)malloc(headNode->cnt + 1);
	memset(ans, 0, headNode->cnt + 1);

	printf("cnt %d \n", headNode->cnt);
	i = headNode->cnt - 1;
	while (StackEmpty(headNode) != 1) {
		ans[i] = (char)StackPop(headNode);
		printf("ans %c \n",ans[i]);
		i--;
	}
	return ans;
}
```