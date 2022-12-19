```
//中序遍历，判断结果是不是从小到大的
int max_val = INT_MIN;
int g_valide = 1;
int g_is_first_val = 0;
void InOrderTravel_1(struct TreeNode *T)
{
    if(T == NULL || g_valide == 0)
    {
        return;
    }
    InOrderTravel_1(T->left);
    //用 g_is_first_val=1去除-2147483648，并g_valide为0时也能提前退出，不需要再次递归
    if((T->val <= max_val) && (g_is_first_val == 1))   
    {
        g_valide = 0;
        return;
    }
    g_is_first_val = 1;
    max_val  = T->val; 
    InOrderTravel_1(T->right);
}

bool isValidBST(struct TreeNode* root)
{
    
    max_val = INT_MIN;
    g_valide = 1;
    g_is_first_val = 0;
    if(root==NULL)  
	{
		return true;
	}	
    if((root->left == NULL && root->right == NULL))   //只有一个值的时候
    {
        return 1;
    }
    InOrderTravel_1(root);   //中序排序
    return g_valide;
}
```
