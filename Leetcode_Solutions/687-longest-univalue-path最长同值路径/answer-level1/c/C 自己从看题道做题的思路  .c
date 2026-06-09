### 解题思路

**原版地址：**https://blog.csdn.net/qq_43539633/article/details/104811840


 一开始搞错了路径的概念，以为题目的意思是计算出所有连着的并且相同的数之和。
例如上面的例子中，我之前写的算出来是 4，但实际上这个答案应该是3。后来查了最大路径的概念才知道指的是：能不重复的遍历最多顶点的一条路径。

 当明白题目要说啥时，我却越来越不懂了。因为之前的代码其实很简单，就是基本的判断、累加最后再返回值。但是真正题目的意义并非于此。为了防止一个节点左子树和右子树相同时重复加的情况，我本想加个判断条件，但是这样就忽略了该节点就是最大路径的节点的情况。所以大概率应该是要用两个变量来找到最大值，一个用来存放最大值，一个用来存放当前节点存在的路径的值。然后来到具体的实现思路，拿上面例子的左下3个数来举例，我开始想实现每个结点中的*Cur_num*传递给其他结点并且值不变，这样可以避免重复加的情况，可是当左子树通过根节点到达右子树的时候，我发现了问题所在，这个值没法向下传递，因为调用它的是上一个节点。为此我想了很长时间（你们也可以想想有没有什么好的解决思路），我想：我将*Cur_num* 向下传递的意义是啥？是为了累加下面有可能和本节点相同的值，于是我就直接更新了Max，那我如何实现只取两边之一的最大值呢？我用三段式更改Cur_num的值。和我之前的思路唯一不一样的就是，我提前更改了Max的值，之前都是放在最后检查，看是否最大而已。




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


//上面描述的有点不恰当，不仅仅使用了两个变量，但是整体思路依然正确，不妨碍大家阅读
int longest(struct TreeNode *root, int val, int *max)
{
    if (root == NULL)
        return 0;
    int num = 0, mark = 0, num1, num2;
    num1 = longest(root->left, root->val, max);
    if (root->val == val) //val是上一层传过来的，root->val是该节点的值
        mark = 1;//mark是用来判断返回值
    num2 = longest(root->right, root->val, max);
    if (num1 + num2 > *max)//这里的max实现了累加两边
        *max = num1 + num2;
    num = (num1 > num2) ? num1 : num2;//num只取了两边之一的最大值
    if (mark == 1)
    {
        return num + 1;
    }
    else
    {
       return 0;
    }
}
int longestUnivaluePath(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int *max = (int *)malloc(sizeof(int));
    *max = 0;
    longest(root, root->val, max);
    return *max;
}
       
```


```