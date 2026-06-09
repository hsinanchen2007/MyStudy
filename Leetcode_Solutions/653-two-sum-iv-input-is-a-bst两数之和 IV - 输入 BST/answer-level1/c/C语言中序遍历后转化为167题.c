int num = 0;
/* 中序遍历二叉树 */
int inVisitBiTree(struct TreeNode* InRoot, int* a)
{
    if(InRoot)
    {
        /* 遍历左子树 */
        inVisitBiTree(InRoot->left,a,k);


        /* 先遍历根节点 */
       // printf("%d~ ",InRoot->val);
        a[num] = InRoot->val;
        num++;
        /* 遍历右子树 */
        inVisitBiTree(InRoot->right,a,k);

    }
    return num;
}

bool findTarget(struct TreeNode* root, int k){
    int a[100000] = {0};
    num = 0;
    int right = inVisitBiTree(root, a)-1;
    int left = 0;
    while(left<right) {
        if(a[left]+a[right]>k) {
            right--;
        }else if(a[left]+a[right]<k) {
            left++;
        }else{
            return true;
        }
    }
    return false;

}

1、num设置为全局变量是因为不是全局有奇怪的报错。
2、整体思路是通过inVisitBiTree函数将二叉树变成一个升序的数组，之后转化为167题求解。