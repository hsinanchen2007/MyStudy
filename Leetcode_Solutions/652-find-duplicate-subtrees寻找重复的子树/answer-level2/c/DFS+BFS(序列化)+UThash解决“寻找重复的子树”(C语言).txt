### 解题思路
本题充分暴露了C的短板。解决本题需要处理以下4个子问题：

1.数字转字符串：通过手写函数实现

2.树的序列化：使用BFS实现

3.查重：使用uhash实现

4.遍历树节点：使用DFS实现

![image.png](https://pic.leetcode-cn.com/5fe8984c36f616e59032314facd4413c2a13332c559bc9c60408394e28d9d9f2-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=652 lang=c
 *
 * [652] 寻找重复的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define CHR_SIZE    200
#define POOL_SIZE   5000
#define QUE_SIZE    POOL_SIZE
#define RES_SIZE    POOL_SIZE

typedef struct _hash_st
{
    char key[CHR_SIZE];
    int val;
    UT_hash_handle hh;
}hash_st;

typedef struct TreeNode tree_st;

// 数字转字串
char tmps[CHR_SIZE];

void itoa(int n, char *s)
{
    if(n == 0)
    {
        s[0] = '0';
        s[1] = '\0';

        return;
    }

    bool minu = false;
    int tsize = 0;
    if(n < 0)
    {
        minu = true;
        n = -n;
    }

    while (n > 0) {
        tmps[tsize++] = n % 10 + '0';
        n /= 10;
    }

    int ssize = 0;
    if(minu == true)
    {
        s[ssize++] = '-';
    }

    //反序输出
    for(int i = tsize - 1; i >= 0; i--)
    {
        s[ssize++] = tmps[i];
    }

    //收尾
    s[ssize] = '\0';

    //printf("%s\n", s);
}

//BFS层序遍历，序列化
tree_st *que0_[QUE_SIZE];
tree_st *que1_[QUE_SIZE];

tree_st **que0;
tree_st **que1;

//hash查找
hash_st *pool;
int psize;
hash_st *head;

//返回结果
tree_st *res[RES_SIZE];
int rsize;

// 将树序列化并查找重复节点，值用‘,’分割，空子树用#表示，结尾‘\0’
void helper(tree_st *root)
{
    //printf("root->val :%d\n", root->val);
    //处理本节点序列化,逐层遍历构建序列化
    hash_st *cur = &pool[psize];
    cur->val = 1;
    char *key = cur->key;

    que0 = que0_;
    que1 = que1_;

    int qsize0 = 0;
    int qsize1 = 0;

    que0[qsize0++] = root;
    //写本级结果，后面迭代写下一级结果
    itoa(root->val, key);

    //printf("root key: %s\n", key);

    while(qsize0 > 0)
    {
        for(int i = 0; i < qsize0; i++)
        {
            tree_st *node = que0[i];

            int klen = strlen(key);
            //本节点信息已经在上次处理加入到key中
            key[klen++] = ',';

            //检查左子树
            if(node->left != NULL)
            {
                itoa((node->left)->val, key + klen);
                klen = strlen(key);
            }
            else {
                key[klen++] = '#';
            }
            key[klen++] = ',';

            //检查右子树
            if(node->right != NULL)
            {
                itoa((node->right)->val, key + klen);
                klen = strlen(key);
            }
            else {
                key[klen++] = '#';
            }

            //收尾
            key[klen] = '\0';

            //准备下次迭代
            if(node->left != NULL)
            {
                que1[qsize1++] = node->left;
            }

            if(node->right != NULL)
            {
                que1[qsize1++] = node->right;
            }
        }
        //printf("----key:%s\n", key);

        tree_st **tmpq = que0;
        que0 = que1;
        que1 = tmpq;

        qsize0 = qsize1;
        qsize1 = 0;
    }
    //printf("seriel key: %s\n", key);

    //检查hash是否找到重复
    hash_st *tmph;
    HASH_FIND_STR(head, key, tmph);

    if(tmph == NULL)
    {
        //增加新节点
        HASH_ADD_STR(head, key, cur);
        psize++;
    }
    else
    {
        //更新原节点及结果输出
        if(tmph->val == 1)
        {
            res[rsize++] = root;
        }

        tmph->val++;
    }

    //调用分析下一级
    if(root->left != NULL)
    {
        helper(root->left);
    }

    if(root->right != NULL)
    {
        helper(root->right);
    }
}

//【算法思路】dfs+树序列化+hash。
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize){
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    pool = (hash_st *)calloc(POOL_SIZE, sizeof(hash_st));
    psize = 0;

    head = NULL;
    rsize = 0;
    helper(root);

    *returnSize = rsize;
    return res;
}


// @lc code=end


```