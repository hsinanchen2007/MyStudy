# 代码如下所示：

广度优先搜索实现思想：
1. 建立一个栈
2. 把当前层的数据放入栈中
3. 根据当前层的数据把下一层的数据放入栈中。


```
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode *arr[2000];
    int ** ret  = (int **)malloc(sizeof(int *) * 2000);
    int top = -1;
    int temp;
    int flag = 0;
    int num;
    int row = -1;
    int index = 0;
    int topTemp = 0;
    int j = 0;

    if (NULL == root) {
        *returnSize = 0;
    }

    //内存分配
    *returnColumnSizes = malloc(sizeof(int *) * 2000);
    
    temp = top;
    arr[++top] = root;
    
    while (1) {
        
        num = top - temp;
        row++;
        (*returnColumnSizes)[row] = num;                // 返回数据赋值
        ret[row] = (int *) malloc(sizeof(int) * num);   // 返回数据

        topTemp = top;
        j = 0;
        while (temp < topTemp) {
            temp++;

            //返回数据赋值
            if (0 == flag) {
                ret[row][j] = arr[temp]->val;
            } else {
                ret[row][num - 1 - j] = arr[temp]->val;
            }
            
            //放入栈中
            if (NULL != arr[temp]->left) {
                arr[++top] = arr[temp]->left;
            }
            if (NULL != arr[temp]->right) {
                arr[++top] = arr[temp]->right;
            }
        }
        flag = 1 - flag;  //返回数据赋值标识（从左到右，或者是从右到左）
        if (topTemp == top) {
            break;  //说明没有元素放入进来
        }
    }
    *returnSize = row + 1;
    return ret;

}
```
![截图.PNG](https://pic.leetcode-cn.com/7cd451c0d82f4eee3abf1cd69b349b3eaf989d5dce53f99fc9141a0d1338044b-%E6%88%AA%E5%9B%BE.PNG)
