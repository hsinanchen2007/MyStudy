### 解题思路
设置一个队列 存储每个节点，当读取都某个节点赋值到返回值中，并让其出队列，并将子节点从尾部入队列
利用队列先进先出保证上一层永远先对列，下一层后出队列。其中增加当前node节点和下一层的nod节点
利用*returnSize表示当前等层数下一层入队列 nextlevelnode++  上一层出队列curtlevelnode--.curtlevelnode=0表示该层读取完毕进入下一层
curlevelnode = nextlevelnode; // 将下一层节点数赋予当前节点数，在下次while循环时开启下一个level的遍历
nextlevelnode = 0;
*returnSize = *returnSize +1 ;

### 代码
![20200401-165413(eSpace).png](https://pic.leetcode-cn.com/43699d85d54f992037f843b2c7332ca3dfbb9271e2b5be93a46c7cb5df4ca80c-20200401-165413\(eSpace\).png)

```c
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

 //类似102题

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // 0 * returnSize 用这个表示当前level层数，初始化为0
    * returnSize = 0;
    //1 异常值返回
    if(root ==NULL){
        return NULL;
    }
    //2 设置队列存放数据：所有的节点先尾部入队列再head读取节点，并尾部存入该节点的子节点
    //利用队列特性先进先出保证按照上层节点先输出，下层节点后输出
    int queuesize = 5; //初步设置队列长度为5，不够再relloc
    int head =0;
    int tail =0;
    struct TreeNode** queue = (struct TreeNode**)malloc(queuesize * sizeof(struct TreeNode*)); 
    queue[tail] = root ;
    // 3设置当前节点个数和下一节点个数。读取当前节点时计算当前节点-- 存入子节点时 下层节点++，判断当前节点个数知道当层是否循环完
    // 设置当前level已读取节点的个数，返回值ret
    int curlevelnode = 1;
    int nextlevelnode = 0;
    int cur_level_cnt = 0;
    int** ret;
    //4循环读取 队列，并将子节点从尾部入队，左右交替入队
    while(head <= tail){//队列不为空
    //5第一次进入该层 ,申请内存
        if(cur_level_cnt==0){
            if(*returnSize == 0){ //表示第一次进入循环 给* returnColumnSizes ret申请内存
                ret = (int **) malloc((*returnSize + 1) * sizeof(int *));
                *returnColumnSizes = (int *) malloc((*returnSize + 1) * sizeof(int *));
            }
            else{
                ret = (int **) realloc(ret,(*returnSize + 1) * sizeof(int *));
                *returnColumnSizes = (int *) realloc(*returnColumnSizes,(*returnSize + 1) * sizeof(int *));
            }
            ret[*returnSize ] = (int*)malloc(curlevelnode * sizeof(int));
            (*returnColumnSizes)[*returnSize] = curlevelnode ;
        }
    
        //6 正常出队列
        struct TreeNode* node =queue[head++];
        ret[*returnSize][cur_level_cnt++] = node->val;
        curlevelnode --;
        //7正常存储队列
        if (node->left != NULL) { 
            if (tail == queuesize - 1) { // 当队列的内存不够
                queue = (struct TreeNode**)realloc(queue, (queuesize += 5) * sizeof(struct TreeNode*));
            }   
            queue[++tail] = node->left; 
            nextlevelnode++; // 下一level的节点数+1
        }  
        if (node->right != NULL) {
            if (tail == queuesize - 1) {
                queue = (struct TreeNode**)realloc(queue, (queuesize += 5) * sizeof(struct TreeNode*));
            }  
            queue[++tail] = node->right;
            nextlevelnode++;
        }
         //8 判断当前层是否出栈完
        if (curlevelnode == 0) { // 当前level节点数==0
        //9 如果当前是奇数列 将ret[*returnSize]数组倒过来即可
            if(*returnSize % 2){
                for(int j=0;j<cur_level_cnt/2 ;j++){
                    int tmp =   ret[*returnSize][j] ;
                    ret[*returnSize][j] = ret[*returnSize][cur_level_cnt -j -1];
                   ret[*returnSize][cur_level_cnt -j -1] = tmp;
                }
            }
        //10 将  curlevelnode cur_level_cnt nextlevelnode nextlevelnode 赋值 读取下一层
            curlevelnode = nextlevelnode; // 将下一层节点数赋予当前节点数，在下次while循环时开启下一个level的遍历
            nextlevelnode = 0;
            cur_level_cnt = 0;
            *returnSize = *returnSize +1 ;    
        }
    }
    free(queue);
    return ret;
    

}
```