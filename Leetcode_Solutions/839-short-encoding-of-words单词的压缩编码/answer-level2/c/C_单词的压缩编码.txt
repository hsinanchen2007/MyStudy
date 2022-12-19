### 解题思路
先倒置再比大小的这种解法有个前提，就是子单词一定出现在母单词倒数第一个字母到倒数第n个字母的位置，例如 time 和 me 、 here 和 re 这样没问题 ,对于 bell 和 el 、 hello 和 ell 这样就不灵了。不过根据题目设定，不回出现bell 和 el 、 hello 和 ell这样的情况。
单词树的解法同样也是考虑到了这个问题，所以树根是单词的最后一个字母，第n层是倒数第n个字母。但是单词树的另一个问题在于这不是一颗二叉树，所以树的节点写起来比较麻烦。

### 代码

```c
//__________________________________________________________________单词链表
typedef struct Node {
	char data;
	struct Node* next;
}Node;
//新建节点
Node* newNode(char Data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = Data;
	n->next = 0;
	return n;
}
//存入一个字符
void push(Node* Head, char Data)
{
	Node* n = newNode(Data);
	n->next = Head->next;
	Head->next = n;
}
//测量单词长度
int lenght(Node* Head)
{
	int result = 0;
	for (Node* n = Head->next; n != 0; n = n->next)
		++result;
	return result;
}
//释放内存
Node* del(Node* Head)
{
	while (Head != 0)
	{
		Node* n = Head;
		Head = Head->next;
		free(n);
	}
	return 0;
}
//__________________________________________________________________快速排序
void sort(Node** Words, int Low, int High)
{
	if (Low < High)
	{
		int l = Low, h = High;
		Node* temp = Words[Low];
		while (l != h)
		{
			while (l<h&&Words[h]->data>temp->data)--h;
			if (l < h)Words[l++] = Words[h];
			while (l < h&&Words[l]->data < temp->data)++l;
			if (l < h)Words[h--] = Words[l];
		}
		Words[l] = temp;
		sort(Words, Low, l - 1);
		sort(Words, l + 1, High);
	}
}
//__________________________________________________________________
int minimumLengthEncoding(char  *words[], int wordsSize) {
	//储存单词链表头结点的数组
	Node** allWords = (Node**)malloc(sizeof(Node*)*wordsSize);
	for (int i = 0; i < wordsSize; ++i)
	{
		allWords[i] = newNode(0);
		for (int j = 0; words[i][j] != '\0'; ++j)
			push(allWords[i], words[i][j]);
		allWords[i]->data = allWords[i]->next->data;
	}
	//排序
	sort(allWords, 0, wordsSize - 1);
	//按照头字母分组对比
	int high = 0, low = 0;
	while (high < wordsSize)
	{
		while (high + 1 < wordsSize&&allWords[high]->data == allWords[high + 1]->data)++high;
		while (low < high)
		{
			if (allWords[low] == 0)
			{
				++low;
				continue;
			}
			for (int i = low + 1; i <= high; ++i)
			{
				if (allWords[i] == 0)continue;
				Node* iter1 = allWords[low]->next;
				Node* iter2 = allWords[i]->next;
				while (iter1 != 0 && iter2 != 0)
					if (iter1->data == iter2->data)
					{
						iter1 = iter1->next;
						iter2 = iter2->next;
					}
					else
						break;
				if (iter1 == 0) 
				{
					allWords[low] = del(allWords[low]);
					break;
				}
				else if (iter2 == 0)allWords[i] = del(allWords[i]);
			}
			++low;
		}
		low = high + 1;
		high = high + 1;
	}

	int result = 0;
	for (int i = 0; i < wordsSize; ++i)
		if (allWords[i] != 0)
		{
			result = result + lenght(allWords[i]) + 1;
			allWords[i] = del(allWords[i]);
		}
	free(allWords);
	return result;

}
```