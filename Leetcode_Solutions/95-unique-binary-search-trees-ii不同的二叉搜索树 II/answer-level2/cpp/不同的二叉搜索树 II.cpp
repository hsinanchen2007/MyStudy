### 解题思路

啊~~~超级难 可能是我太菜了，花了我大半天的时间，才终于弄出来，还是看了别人的程序。
其实我对C++不是很熟悉，static修饰符也从来没有用过，好不容易弄明白了思路之后，敲了代码，结果……超过时间限制，嗯……其实我也没搞明白是哪里的问题[尴尬]
主要的思路呢，还是动态规划吧，这么说不知道清不清楚，连续n个数构成二叉搜索树的情况其实是一样的，比如说：1-5和3-8的所有情况，想象一下，是不是一样的，只是后面实例的数=前面实例对应位置上的数+3.
所以……如果我们已经有了1的所有可能情况dp[1]，其实就是以1位根节点的那一种；
??? 1-2的所有可能情况怎么去考虑呢 ??? dp[2]
以1为根节点，2只能为1的右节点，以2为根节点的子树情况其实与以1为根节点的情况一致，只是对应位置上的数值+1；dp[2][1]
以2位根节点，1只能为2的左节点，以1位根节点的子树情况我们已经有了呀，就是dp[1];dp[2][2]
??? 1-3的所有可能情况呢 ??? dp[3]
以1为根节点，以2为根节点、3为右节点的子树（这不就是我们的dp[2][1]吗？只是节点值=比dp[2][1]对应位置+1罢了）只能是1的右节点；同样的，以3为根节点、2为左节点的子树与dp[2][2]对应；
以2为根节点，那么1为左节点，3为根节点（其实就是我们的dp[1]对应位置+2罢了）；
以3位根节点，以1为根节点、2为右节点的子树（与dp[2][1]对应）；同样的，以2为根节点、1为左节点的子树与dp[2][2]对应）
??? 1-4的所有可能情况呢 ??? dp[4]
以1为根节点，包含2、3、4三个节点的子树（其实就是我们dp[3]中的所有情况对应位置+1）只能是1的右节点;
以2为根节点，则1为2的左节点（dp[1]），包含3、4两个节点的子树（dp[2]中的所有情况对应位置+2）只能是2的右节点；
以3为根节点，则包含1、2两个节点的子树（dp[2]）只能是3的左节点，4为3的左节点（dp[1]+3）；
以4为根节点，则包含1、2、3三个节点的子树（dp[3]）只能为4的左节点
…………………………………………………………………………………………………………………………………………………………………………………………………………………………………………
上面讲清楚了吗？这已经是我的极限了~~~
基于这个思想：1-n所有值都有可能作为根节点，我们依次去找以某个值为根节点的所有可能情况，皆可以产生代码啦~但是！遇到了一个时间限制的问题，是为什么呢？我觉得可能是数组定义上面的毛病，然而不是很确定，有一位大佬用了static，因为我不会用static啦，所以只能从代码中分析意思：
应对不同的测试用例n，如果我之前已经通过了n=10的实例，意味着我dp[0]~dp[10]都已经产生了，面对n=12的用例，我只需要产生dp[11]、dp[12]两行结果就行啦，多省时间呀！厉害！厉害！厉害！
查了一下
auto（拷贝不改变）,
auto&（拷贝可修改）,
const auto（拷贝不修改）,
const auto&（只读不拷贝）[不太清楚加不加&的空间优越性]
那用了static，我还想对static修饰的变量dp修改用什么？auto&
如果要访问某个数组，又不想拷贝，那就用const auto&，“只读不拷贝”听着就能节省不少空间吧。
好了，还是看代码吧^.^

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0) return {};
        static vector<vector<TreeNode*>> dp(1, vector<TreeNode*>(1, NULL));
        int o_size=dp.size();
        if(n+1>dp.size())
            dp.resize(n+1); //动态变化dp的大小
        for(int i=o_size; i<=n; i++){  //面对新的用例，只添加之前没有出现过的
            for(int root=1; root<=i; root++){
                const auto &leftDP=dp[root-1];
                const auto &rightDP=dp[i-root];
                auto &cc=dp[i];
                for(const auto leftBranch: leftDP){
                    for(const auto rightBranch: rightDP){
                        TreeNode *temp=new TreeNode(root);
                        if(root>1)
                            temp->left=leftBranch;
                        if(root<i)
                            temp->right=clone(rightBranch, root);
                        cc.push_back(temp);
                    }
                }
            }
        }
        return dp[n];
    }
    TreeNode* clone(TreeNode *subtree, int offset){
        TreeNode *res=new TreeNode(subtree->val+offset);
        if(subtree->left)
            res->left=clone(subtree->left, offset);
        if(subtree->right)
            res->right=clone(subtree->right, offset);
        return res;
    }
};
```