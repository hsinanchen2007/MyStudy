### 解题思路
用二叉树来解题 -向左枝 .向右枝
每个单词能生成一个自己的“摩尔斯路径”，路径的终点做一个标记。
最后统计标记的数量，就是不同摩尔斯密码的数量。
### 代码

```c
//树的节点
typedef struct Node {
	int num;
	struct Node * left;
	struct Node * right;
}node;
//生成一个节点
node* newNode()
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->num = 0;
	newNode->left = 0;
	newNode->right = 0;
	return newNode;
}
//销毁树,统计数量
void deletTree(node* root, int *sum)
{
	if (root == 0)
		return;

	deletTree(root->left, sum);
	deletTree(root->right, sum);
	*sum += root->num;
	free(root);
}

int uniqueMorseRepresentations(char ** words, int wordsSize) {
	if (wordsSize == 0)return 0;
	//摩尔斯密码词典
	char *s[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
	//建一棵编码树
	node* root = newNode();
	node* iterTree = root;
	//逐单词遍历
	for (int i = 0; i < wordsSize; ++i)
	{
		//第i个单词，逐字母c遍历
		char *c = words[i];
		while (*c != '\0')
		{
			//提取出字母对应的摩尔斯密码
			char *iter = s[(int)(*c - 'a')];
			//根据摩尔斯密码的点和线生成编码树
			while (*iter != '\0')
			{
				//如果是个'-' 向左伸一个枝
				if (*iter == '-')
					if (iterTree->left != 0)
						iterTree = iterTree->left;
					else
					{
						iterTree->left = newNode();
						iterTree = iterTree->left;
					}
				//如果是个'.'向右伸一个枝
				else if (*iter == '.')
					if (iterTree->right != 0)
						iterTree = iterTree->right;
					else
					{
						iterTree->right = newNode();
						iterTree = iterTree->right;
					}
				++iter;
			}
			++c;
		}
		//下一个单词 树又要从根开始延伸
		iterTree->num = 1;
		iterTree = root;
	}
	//多少叶子节点，不同单词翻译数量就是多少
	int sum=0;
	deletTree(root, &sum);
	return sum;
}
```