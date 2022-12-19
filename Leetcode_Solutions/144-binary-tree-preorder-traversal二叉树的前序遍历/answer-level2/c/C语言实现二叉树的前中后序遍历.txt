C++也是这样的逻辑，只需把自己模拟的栈改为C++库 stack 调用即可

执行结果：通过
显示详情
执行用时 :
0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :
5.5 MB, 在所有 C 提交中击败了100.00%的用户


struct Command{
	bool bcommandType;		//true:访问节点，false:打印节点
	struct TreeNode* node;
};


//非递归，模拟栈实现前序遍历
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int *res = (int*)malloc(sizeof(int)*100);		//输出数组
	int TopOfStack = -1;		//栈顶元素
	struct Command stack[100];			//模拟系统栈，栈中存储指向Command结构体的地址
	
	*returnSize = 0;

	if(root == NULL)
	{
		return res;
	}

	//访问根节点
	stack[++TopOfStack].bcommandType = true;
	stack[TopOfStack].node = root;

	while(TopOfStack != -1)
	{
		struct Command command;

		command.bcommandType = stack[TopOfStack].bcommandType;		//出栈
		command.node = stack[TopOfStack--].node;

		if(command.bcommandType == false)			//打印
		{
			res[(*returnSize)++] = command.node->val;
		}
		else			//访问节点
		{
			//打印节点元素，推入栈 ----------后序遍历
			//stack[++TopOfStack].bcommandType = false;
			//stack[TopOfStack].node = command.node;

            //如果右儿子存在，则访问右儿子，推入栈
			if(command.node->right)
			{
				stack[++TopOfStack].bcommandType = true;
				stack[TopOfStack].node = command.node->right;
			}

            //打印节点元素，推入栈 ----------中序遍历
			//stack[++TopOfStack].bcommandType = false;
			//stack[TopOfStack].node = command.node;

			//如果左儿子存在，则访问左儿子，推入栈
			if(command.node->left)
			{
				stack[++TopOfStack].bcommandType = true;
				stack[TopOfStack].node = command.node->left;
			}

			//打印节点元素，推入栈 ----------前序遍历
			//stack[++TopOfStack].bcommandType = false;
			//stack[TopOfStack].node = command.node;
		}
	}
    printf("returnSize=%d\n",*returnSize);
	
	return res;
}