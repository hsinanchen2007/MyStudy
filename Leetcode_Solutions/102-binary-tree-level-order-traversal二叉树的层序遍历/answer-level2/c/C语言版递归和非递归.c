\
\
# 非递归版
![image.png](https://pic.leetcode-cn.com/dad45ba5beb7c926931fae24c6ae5163ba262f88011b8cc366619109a6ecd807-image.png)
\
\
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 想法是将将二叉树一层一层放到数组中，比如一般访问左子树之后就只能
// 继续往下面找，本解法将每层访问的左右子树保存下来就能实现一层层的访问

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int index1 = 0; // 该层第一个元素
    int index2 = 0; // 下一层的起始元素
    struct TreeNode** treeArray = malloc(sizeof(struct TreeNode*) * 5000); //存放各层树节点
    treeArray[0] = root; // 首先将根节点放到数组中
    index2 = 1; // 放入第一层，更新index2
    int preindex1 = index1; // 因为index1 和 index2 在我访问过程中需要变动记录
                           // 访问到哪了，为了访问完此层后的统计，需要储存index初始值。
    int preindex2 = index2; 


    int **res = malloc(sizeof(int*) * 2000); // 最后返回的结果
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2000);
    memset(*returnColumnSizes,0,sizeof(int) * 2000);

    int i=0; //记录结果数组当前放到第几层了
    int count = 0; //统计每一层null的数量
    while(index1 < index2){
        if(treeArray[index1] == NULL){  //当前节点为null，访问下一个节点并计数
            index1++;
            count++;
        }
        else{
            treeArray[index2] = treeArray[index1]->left; //当前节点左子节点存入
            index2++;
            treeArray[index2] = treeArray[index1]->right; //当前节点右子节点存入
            index2++;
            index1++; //访问下一个节点
        }
        if(index1 == preindex2){ //index1达到上次记录的右边界，即访问完一层
            res[i] = malloc(sizeof(int) * (preindex2  - preindex1)); //统计此层宽度，申请空间
            int kk = 0;
            for(int j = 0;j < preindex2 - preindex1;j++){ //循环访问此层，添加到结果数组
                if(treeArray[preindex1 + j] != NULL){
                    res[i][kk] = treeArray[preindex1 + j]->val;
                    kk++;
                }
            }
            i++; //结果数组的层数加1
            (*returnColumnSizes)[i-1] = preindex2 - preindex1 - count; //统计此层除null之外的真正宽度
            count = 0;
            preindex1 = index1;//更新下一层边界
            preindex2 = index2;
        }
    }
    for(int aa = i;aa>=0;aa--){ //遍历下防止最后加了几层空数组
        if((*returnColumnSizes)[aa] != 0){
            *returnSize = aa+1;
            break;
        }
        if(aa==0) //如果根节点为null，返回空
            *returnSize = 0;
    }
    return res;
}
```
\
\
\
\
# 递归
因为C语言的数组限制比较多，不易调整，所以我一开始就各层设定了大小，浪费较多，时间上也不快
\
\
![image.png](https://pic.leetcode-cn.com/2aebbbe080c1952ca5187ce870324a942603e8c4079c8a14bd2a87b5b2b50e29-image.png)


```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = malloc(sizeof(int*) * 1000); //结果数组
    for(int i=0;i<1000;i++) //全部初始化为1个特殊的元素。以便后面统计每排有几个
    {
        res[i] = malloc(sizeof(int) * 200);
        for(int j=0;j<200;j++)
            res[i][j] = -929;
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    order(root,0,res); //递归


    for(int i=0;i<1000;i++) //确定返回元素每一层的宽度
    {
        if(res[i][0]==-929) //如果某一层第一个就是特殊元素，则这一层都没有存数据，即结束
        {
            *returnSize = i;
            break;
        }
        for(int j=0;j<200;j++) //统计每一层有多少元素存入
        {
            if(res[i][j]==-929)
                {
                    (*returnColumnSizes)[i] = j;
                    break;
                }
        }
    }
    return res;
}

void order(struct TreeNode* root,int k,int** res) 
     {
         if(root==NULL)
            return;
        for(int i=0;i<1000;i++) //到第一个未填的位置填入当前值
            if(res[k][i]==-929)
                {
                    res[k][i]=(root->val);
                    break;
                }
        order(root->left,k+1,res); //递归左子节点
        order(root->right,k+1,res);  //递归右子节点
     }

```
