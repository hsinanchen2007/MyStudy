int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	* returnSize=0;
	if (!root) {return NULL;}
	//初始化列表
	struct node
	{
		struct TreeNode* data;
		struct node *next;
	};
	struct node *head=malloc(sizeof(struct node));
	head->data=root;
	head->next=NULL;
	struct node *rear=head;
	int cnt1=1,j=0;
	int **ret=malloc(sizeof(int*)*1000);
	* returnColumnSizes=malloc(sizeof(int)*1000);
	while(cnt1)
	{
		int cnt2=0;
		ret[j]=malloc(sizeof(int)*cnt1);
		for (int i=0;i<cnt1;i++)
		{
			if (head->data->left){
				struct node *newnode=malloc(sizeof(struct node));
				newnode->data=head->data->left;
				newnode->next=NULL;
				rear->next=newnode;
				rear=rear->next;
				cnt2++;
			}
			if (head->data->right){
				struct node *newnode=malloc(sizeof(struct node));
				newnode->data=head->data->right;
				newnode->next=NULL;
				rear->next=newnode;
				rear=rear->next;
				cnt2++;
			}
			ret[j][i]=head->data->val;
			struct node *temp=head;
			head=head->next;
			free(temp);
		}
		(*returnColumnSizes)[j]=cnt1;
		cnt1=cnt2;j++;
	}
	* returnSize=j;
	return ret;
}