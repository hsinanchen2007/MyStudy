# 题目思路
理解这个题目之前，可以先理解一下对区间和哈希的类似算法：[区间内累加和为规定值的最长子序列](https://blog.csdn.net/qq_35976351/article/details/103864846)。

对于一维的线性结构，我们要求解满足符合长度的子区间的序列和，可以采用以下思路，利用数据分段累计的方式，在线计算：
假设序列是arr[0…N]，假设我们知道从0-N，每个自区间的和，即任意的k在[0…N]中，我们都知道arr[0…k]所有元素的和，记为sum(k)。那么对于任意的i>j，sum(i) - sum(j) = k，表示[j+1…i]的所有元素的和。因此，我们每次把已经累加完的sum(i)放到哈希表中，如果当前位置是j，而且0..j的累加和是sum(j)，如果存在区间的累加和是k，那么sum(j) - k必然在哈希表中，因此找到一个区间。注意，需要在开始的时候存储一个0，处理头节点满足条件的情况。

有多个区间的情况，比如[0, 0, 1, 0]中求解累加和是1的区间，有5个，分别是[0, 0, 1]，[0, 1]，[1], [1, 0], [0, 0, 1, 0]，此时需要用多键值哈希的方式存储个数。sun(j) - k如果在哈希表中，需要统计满足的个数，此时是新元素加入后的区间数量。

对于二叉树，树是二维的结构，为了把二维结构转换成一维结构，可以用先序遍历的方式，不断递增一维序列，代替上述一维结构中的遍历，记得在递归结束的时候，弹出对应的元素，可以参考[这个笔记](https://blog.csdn.net/qq_35976351/article/details/103871084)，一个类似的思路。

# AC代码
```cpp
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        N = sum;
        umst.insert(0);  // 处理头节点的特殊情况
        PreOrder(root, 0);
        return res;
    }
    // 先序遍历模拟序列递增
    void PreOrder(TreeNode* root, long sum) {
        if (root == nullptr) {
            return;
        }
        long s = sum + root->val;
        long k = s - N;
        int t = umst.count(k);
        res += t;  // 累加相等的区间，注意是多个，参考题解对应[0, 0, 1, 0]的描述
        umst.insert(s);
        PreOrder(root->left, s);
        PreOrder(root->right, s);
        auto it = umst.find(s);
        umst.erase(it);  // 利用迭代器，仅仅清空一个。这是递归结束，清空不需要的元素了
    }
    std::unordered_multiset<long> umst;
    int res{0};
    int N{0};
};
```
