### 解题思路
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"



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
/** Encodes a tree to a single string. */
#define LEN 21000
char* serialize(struct TreeNode* root) {
    struct TreeNode *queue[LEN] = {0};
    int r = 1, w = 0, size;
    char temp[LEN*4] = {0};

    if (root == NULL)
        return NULL;

    queue[0] = root;
    sprintf(temp, "%d",root->val);
    queue[1] = queue[0]->left;
    queue[2] = queue[0]->right;
    w = 3;
    while(r < w) {
            if (queue[r]) {
                sprintf(temp, "%s,%d", temp, queue[r]->val);
                queue[w++] = queue[r]->left;
                queue[w++] = queue[r]->right;
            } else
                sprintf(temp, "%s,null", temp);

            r++;
    }

    int len = strlen(temp);
    
    char *res = malloc(len + 1);
    strncpy(res, temp, len);
    res[len] = '\0';

    return res;
}

int myspit(char *data, char c, char **res) {
    int i = 1;
    char *oldstr = data, *newstr;
    res[0] = data;
    
    while(true) {
        newstr = strchr(oldstr, c);
        if (newstr) {
             *newstr = '\0';
            oldstr = newstr + 1;
            res[i++] = oldstr;
        } else {
            oldstr = NULL;
            break;
        }
    }

    return i;
}

int myatoi(char *str) {
    int val = 0;
    bool minus = false;

    if (*str == '-') {
        str++;
        minus = true;
    }
    while(*str != '\0'){
        val = val *10 + (*str - 48);
        str++;
    }

    return minus ? (0-val):val;
}

struct TreeNode * creatNode(int val){
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;

    return node;
}
/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int i = 1, len, r = 0 , w = 0,j=0;
    struct TreeNode* queue[LEN] = {0};
    char *strarr[LEN] = {0};
    char c = ',';

    if(data == NULL)
        return NULL;

    len = strlen(data);
    myspit(data, c, strarr);
    queue[w++] = creatNode(myatoi(strarr[0]));

    //还是用队列，　把节点放到队列里宽度　来一个个添加val
    while (r < w) {

        if (!strcmp(strarr[i], "null")) {
            queue[r]->left = NULL;
        } else {
            queue[r]->left = creatNode(myatoi(strarr[i]));
            queue[w++] = queue[r]->left;
        }
        
        i++;
        if (!strcmp(strarr[i], "null")) {
            queue[r]->right = NULL;
        } else {
            queue[r]->right = creatNode(myatoi(strarr[i]));
            queue[w++] = queue[r]->right;
        }
        i++, r++;
    }
    return queue[0];
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
```