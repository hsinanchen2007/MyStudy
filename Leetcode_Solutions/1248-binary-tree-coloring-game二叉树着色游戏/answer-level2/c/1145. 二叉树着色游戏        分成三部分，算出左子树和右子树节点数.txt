### 解题思路
有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到 n 各不相同。

 

游戏从「一号」玩家开始（「一号」玩家为红色，「二号」玩家为蓝色），最开始时，

「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；

「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。

「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。

 

之后两位玩家轮流进行操作，每一回合，玩家选择一个他之前涂好颜色的节点，将所选节点一个 未着色 的邻节点（即左右子节点、或父节点）进行染色。

如果当前玩家无法找到这样的节点来染色时，他的回合就会被跳过。

若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。

 

现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true；若无法获胜，就请返回 false。

 

示例：



输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
输出：True
解释：第二个玩家可以选择值为 2 的节点。




问题分解成，  选手1 最多将树分成三个部分， 选手2要赢必须其中一个部分大于一半节点数。

题意节点只能相邻着色，没有相邻就只能看对手玩了。

递归写复杂了，总个数已经知道了n

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

#define MAX(a,b) ((a) > (b) ? (a) : (b))
int suml,sumr;
int g_x;

int helper(struct TreeNode *root){
    if(root == NULL)
        return 0;
    if(root->val == g_x){
        int l=0,r=0;
        l = helper(root->left);
        r = helper(root->right);
        suml = l;
        sumr = r;
        //printf("%d %d\n",l,r);
        return l + r + 1;
    }else{
        return helper(root->left) + helper(root->right) + 1;
    }
    
}


bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
    int sum = 0;
    sumr = 0;
    suml = 0;
    g_x = x;
    sum = helper(root);
    //printf("%d %d %d\n",sum,suml,sumr);
    return (sum-1)/2 < MAX((sum - suml -sumr -1), MAX(sumr,suml));
}
```