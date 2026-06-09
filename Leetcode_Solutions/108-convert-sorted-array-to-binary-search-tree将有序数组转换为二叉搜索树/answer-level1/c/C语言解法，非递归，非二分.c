```
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

    if(numsSize == 0)
        return NULL;
    struct TreeNode* tree_table[numsSize];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* c = NULL;
    tree_table[0] = root;
    int i = 0, j = 0;

    while(i < numsSize){
        c = tree_table[i];
        if(j < numsSize - 1){
            if(j  < numsSize - 2){
                c->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                c->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                tree_table[j+1] = c->left;
                tree_table[j+2] = c->right;
            }else{
                c->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                c->right = NULL;
                tree_table[j+1] = c->left;
            }
            j = j + 2;
        }else{
            c->left = NULL;
            c->right = NULL;
        }
        i++;
    }

    i = 0;
    j = 0;
    struct TreeNode* loop_table[numsSize];
    loop_table[j] = tree_table[j];
    while(i < numsSize){
        while(loop_table[j]->left != NULL){
            loop_table[j+1] = loop_table[j]->left;
            j++;
        }
        loop_table[j]->val = nums[i++];
        if(loop_table[j]->right != NULL){
            loop_table[j] = loop_table[j]->right;
        }else{
            loop_table[j] = NULL;
            j--;
            while(j >= 0 && loop_table[j]->right == NULL){
                loop_table[j]->val = nums[i];
                loop_table[j] = NULL;
                i++;
                j--;
            }
            if(j < 0)
                break;
            loop_table[j]->val = nums[i++];
            loop_table[j] = loop_table[j]->right;
        }
    }
    return root;
}
```
执行用时 :12 ms, 在所有 c 提交中击败了88.10%的用户
内存消耗 :9.5 MB, 在所有 c 提交中击败了100.00%的用户

（1）解题条件：构造平衡二叉树
解答：按层生产2层树，最终得出的树一定为平衡二叉树

（2）解题条件：输入的数组是升序数组
解答：需以中序遍历的方式将数值填进构造好的平衡二叉树里

总结：就是先以按层生产满二叉树的办法先将锁需要的树构建好，然后以中序遍历的办法取出树节点，将数组上的数字填在节点中。
