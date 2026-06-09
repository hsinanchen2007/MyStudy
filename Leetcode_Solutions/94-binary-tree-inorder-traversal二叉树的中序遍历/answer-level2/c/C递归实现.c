### 解题思路
- 这个题定义的这个函数的形式感觉对C语言不太友好，数组没法动态添加成员，必须得知道数组的大小，所以就不得不先求数中一共有多少节点
  * 首先求数中有多少个节点
  * 然后利用这个大小创建这么多节点的整形数组
  * 然后对这个数组中序遍历依次开始填充，这里我一开始直接设置`returnSize`为0，这个变量在遍历中的含义是数组中已经填充到了第几个元素
  * 中序遍历时操作就是在数组的`*returnSize`这个位置填充当前节点的值，再将`*returnSize`+1即可

### 代码

```c
//  获取数中节点的个数，以便于来创建数组
int getSize(struct TreeNode* node)
{
    if(node == NULL)
    {
        return 0 ;
    }
    else
    {
        return (getSize(node->left)+getSize(node->right)+1);
    }
}

void traversal(struct TreeNode* node ,int* returnSize ,int* arr)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        traversal(node->left,returnSize,arr);
        arr[*returnSize] = node->val ; (*returnSize)++ ; 
        traversal(node->right,returnSize,arr); 
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = getSize(root);

    int* arr = malloc(sizeof(int)*size);

    *returnSize = 0;//先把返回的数组大小设置为0，以便在遍历的时候确定要填写的位置

    traversal(root,returnSize,arr);

    return arr;
}
```