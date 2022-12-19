![QQ截图20190712084533.png](https://pic.leetcode-cn.com/95c4f0e2ab1c9cdd1ecea41ce370a434a8b4ac701c2088bd0a7ef9dcfbb22047-QQ%E6%88%AA%E5%9B%BE20190712084533.png)

顺序二叉树，最适合中序遍历，这样遍历出来的节点的值是依次增大的，就像当于排好顺序的数组。
这道题，主要用中序遍历，依次和前一个节点比较，来判断。
```
int max;     //众数最大值
int pre_num; //前一个元素的众数数量
int pre;     //前一个元素的值
int arr_size;
int *ret_arr;
int* findMode(struct TreeNode* root, int* returnSize){
    max = -1;               //初始化
    pre = 0xffffffff;
    arr_size = 0;
    ret_arr = (int *)calloc(10240, sizeof(int));
    
    if (root == NULL) {
        * returnSize = 0;
        return ret_arr;
    }
    
    find_mx(root);//真正的处理函数

    * returnSize = arr_size;
    return ret_arr;
}
int find_mx(struct TreeNode* root)
{
    if (root->left != NULL) find_mx(root->left);

    if (pre == root->val) ++pre_num;//判断前一个数是否和当前节点相同
    else                  pre_num = 1;
    
    if (pre_num > max) {     //和最大众数数量比较，如果大于就从头开始装入元素
        ret_arr[0] = root->val;
        arr_size = 1;
        max = pre_num;
    }else if (pre_num == max) ret_arr[arr_size++] = root->val;//如果相当就累加装入

    pre = root->val;
    
    if (root->right != NULL) find_mx(root->right);

    return 0;
}
```
