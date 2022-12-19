#define STACK_INIT_SIZE   2000
#define max(a,b) (a>b)?(a):(b)

struct TreeNode_V_and_F
{
	struct TreeNode *stack_v;
	int tree_node_f;/*二叉树节点所在的层级*/
};
struct STACK_NODE
{
	int stack_top_idx;
	struct TreeNode_V_and_F *stack_v_p;
};
/*初始化栈*/
void stack_init(struct STACK_NODE *tree_stack)
{
	tree_stack->stack_top_idx = -1;
	tree_stack->stack_v_p = (struct TreeNode_V_and_F *)malloc(sizeof(struct TreeNode_V_and_F)*STACK_INIT_SIZE);
}

/*向栈压入一个节点*/
void stack_append(struct STACK_NODE *tree_stack,struct TreeNode *Node, int node_f)
{
	(tree_stack->stack_top_idx)++;
	tree_stack->stack_v_p[tree_stack->stack_top_idx].stack_v = Node;
	tree_stack->stack_v_p[tree_stack->stack_top_idx].tree_node_f = node_f;
}

/*栈推出一个节点*/
void stack_pop(struct STACK_NODE *tree_stack,struct TreeNode **Node, int *node_f)
{
	*Node = tree_stack->stack_v_p[tree_stack->stack_top_idx].stack_v;
    *node_f = tree_stack->stack_v_p[tree_stack->stack_top_idx].tree_node_f;
	(tree_stack->stack_top_idx)--;
}

/*释放创建的栈*/
void stack_destroy(struct STACK_NODE *tree_stack)
{
	if (tree_stack == NULL)
	{
		return;
	}
	tree_stack->stack_top_idx = -1;
	free(tree_stack->stack_v_p);
}

int maxDepth(struct TreeNode* root)
{
	struct STACK_NODE Btree_stack = {0,};
	struct TreeNode **root_pp = NULL;
	int cur_node_f = 0;
	int depth = 0;

	depth = 0;
	if (root == NULL)
	{
		return depth;
	}
	cur_node_f = 1;
	stack_init(&Btree_stack);

	/*先把二叉树的根压入栈*/
	stack_append(&Btree_stack,root,cur_node_f);

	root_pp = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
	while (Btree_stack.stack_top_idx > -1)
	{
		/*从栈顶推出一个节点*/
		stack_pop(&Btree_stack,root_pp,&cur_node_f);
		if ((*root_pp) != NULL)
		{
			depth = max(depth,cur_node_f);
			stack_append(&Btree_stack,(*root_pp)->left,cur_node_f+1);
			stack_append(&Btree_stack,(*root_pp)->right,cur_node_f+1);
		}
	}
	free(root_pp);
	stack_destroy(&Btree_stack);
	return depth;
}