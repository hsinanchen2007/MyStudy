当前结点的值，对应当前数组段的最大值，要判断当前结点是否有左子树和右子树，则要判断当前数组段最大值的下标位置，如果下标在最左端或最右端，则只有右子树或左子树，否则两个都有。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxPosition(int* nums, int start, int end)
{
    int max = 0;
    int maxPosition = 0;
    
    for(int i = start; i <= end; i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
            maxPosition = i;
        }
    }
    
    return maxPosition;
}

void constructTree(struct TreeNode* curnode, int* nums, int start, int end)
{

    if(start == end)
    {
        curnode->val = nums[start];
        return;
    }
    
    int maxposition = maxPosition(nums, start, end);
    curnode->val = nums[maxposition];
    
    if(maxposition == start)
    {
        struct TreeNode* node = (struct TreeNode* )malloc(sizeof(struct TreeNode));
        node->left = NULL;
        node->right = NULL;
        
        curnode->right = node;
        constructTree(node, nums, maxposition + 1, end);
    }
    else if(maxposition == end)
    {
        struct TreeNode* node = (struct TreeNode* )malloc(sizeof(struct TreeNode));
        node->left = NULL;
        node->right = NULL;
        
        curnode->left = node;
        constructTree(node, nums, start, maxposition - 1);
    }
    else
    {
        struct TreeNode* node1 = (struct TreeNode* )malloc(sizeof(struct TreeNode));
        node1->left = NULL;
        node1->right = NULL;
        
        struct TreeNode* node2 = (struct TreeNode* )malloc(sizeof(struct TreeNode));
        node2->left = NULL;
        node2->right = NULL;
        
        curnode->left = node1;
        constructTree(node1, nums, start, maxposition - 1);
        curnode->right = node2;
        constructTree(node2, nums, maxposition + 1, end);
    }
    
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    
    if(numsSize == 0)
        return NULL;
    
    struct TreeNode* head = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    head->left = NULL;
    head->right = NULL;
    

    constructTree(head, nums, 0, numsSize-1);
    
    
    return head;
}