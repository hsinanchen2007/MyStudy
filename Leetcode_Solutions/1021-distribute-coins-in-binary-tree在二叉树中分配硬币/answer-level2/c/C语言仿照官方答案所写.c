### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
       示例1：输出2
                3         ans = 2      返回 0
              /   \
             0     0      0 返回 -1    0 返回 -1
          
       示例2：输出3
                0         ans = 3      返回 0
              /   \
             3     0      3 返回 2（它多出来两个金币，先移到父节点处，需要两步）   0 返回 -1（它需要一个金币，从父节点移到这里需要一步）  两步加一步 = 3
       
       示例3：输出2
                1         ans = 2      返回 0
              /   \
             0     2      0 返回 -1    0 返回 1                 
       
       示例4：输出4
                1         ans = 2      返回 0     ans = 4
              /   \
             0     0      0 返回 1    0 返回 -1   ans = 2
              \
               3          左边没有返回0   3返回2   
*/

int ans;

int dfs(struct TreeNode* node)
{
    if(node == NULL)
        return 0;

    int L = dfs(node->left);  //左边需要的金币数 - 左边本身需要的1个金币数  
    int R = dfs(node->right); //右边需要的金币数 - 右边本身需要的1个金币数
    
    int absL = L > 0 ? L : -L;
    int absR = R > 0 ? R : -R;

    ans += (absL + absR);          //所要移动的步数
    return node->val + L + R - 1;  

}


int distributeCoins(struct TreeNode* root) 
{
    ans = 0;
    dfs(root);
    return ans;
}


```