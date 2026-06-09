先序遍历，第一个节点一定是最中间的，假设如此，分别验证左子树和右子树是否正确。
序列中第一个大于根节点的节点之后的节点应该都属于右子树，在此之前的除了根节点的都应该是左子树，需验证右子树所有节点大于根节点，左子树所有节点小于根节点。同时左子树的序列区间和右子树的序列区间，也应该满足同样的验证条件。
将验证逻辑抽象成verify函数，输入当前子树的区间，和上下界。递归校验即可。

应该用栈做。

[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目


```
class Solution {
public:
    bool verify(vector<int>& preorder, int start, int upper, int lower, int end) {
        int middle = preorder[start];

        if (middle > upper || middle < lower) {
            return false;
        }
        if (start >= end - 1) {
            return true;
        }

        bool right = true;
        bool left = true;

        int i;
        for (i = start + 1; i < end; i++) {
            if (preorder[i] > middle) {
                break;
            }
        }

        if (preorder[start+1] <= middle) {
            left = verify(preorder, start+1, min(upper, middle), lower, i);
        }

        if (i < end) {
            right = verify(preorder, i, upper, max(lower, middle), end);
        }

        return left && right;
    }

    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        return verify(preorder, 0, INT_MAX, INT_MIN, preorder.size());
    }
};
```
