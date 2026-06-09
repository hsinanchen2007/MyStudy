

### 解题思路
1、后序遍历过程结合贪心算法
2、后序遍历，左孩子->右孩子->根节点
4、贪心算法，根据左右孩子返回状态，得到根节点状态
5、定义节点4个状态，空指针、无灯光覆盖、有灯光覆盖无灯、有灯光覆盖有灯
6、左右子节点状态、根节点状态直接做成如下表NodeType output

### 代码

```c
typedef enum {
    NULL_PTR = 0,
    NO_LIGHT,
    LIGHT,
    LIGHT_LAMP
}NodeType;

void Dfs(struct TreeNode* root, NodeType* type, int* num)
{
    if (root == NULL) {
        *type = NULL_PTR;
        return;
    }

    NodeType output[LIGHT_LAMP + 1][LIGHT_LAMP + 1] = {
        1, // left=NULL_PTR  right=NULL_PTR
        3, // left=NULL_PTR  right=NO_LIGHT
        1, // left=NULL_PTR  right=LIGHT
        2, // left=NULL_PTR  right=LIGHT_LAMP
        3,
        3,
        3,
        3,
        1,
        3,
        1,
        2,
        2, // left=LIGHT_LAMP  right=NULL_PTR
        3, // left=LIGHT_LAMP  right=NO_LIGHT
        2, // left=LIGHT_LAMP  right=LIGHT
        2  // left=LIGHT_LAMP  right=LIGHT_LAMP
    };

    NodeType leftType;
    NodeType rightType;
    Dfs(root->left, &leftType, num);
    Dfs(root->right, &rightType, num);
    *type = output[leftType][rightType];
    if (*type == LIGHT_LAMP) {
        *num += 1;
    }

    return;
}

int minCameraCover(struct TreeNode* root)
{
    int num = 0;
    NodeType type = NULL_PTR;
    Dfs(root, &type, &num);
    if (type == NO_LIGHT) {
        num++;
    }

    return num;
}
```