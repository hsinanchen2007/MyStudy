# 解题思路：分治算法，使用递归实现。
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.8 MB, 在所有 C 提交中击败了100.00%的用户

数组最后一个元素是根，前面分成两部分：左子树和右子树。
左子树元素均小于root，右子树元素均大于root，不符合这个特征则return false。
分别判断左右子树是否均符合该特征，相与即是结果。


# 代码：

```
bool verifyPostorder(int* postorder, int postorderSize)
{
    if (postorderSize <= 2) {
        return true;
    }
    //找到一个seprate位置，左侧均小于root，右侧(含)应当均大于root。
    int seprate = 0;
    for (seprate = 0; seprate < postorderSize - 1; seprate++) {
        if (postorder[seprate] > postorder[postorderSize - 1]) {
            break;
        }
    }
    for (size_t i = seprate; i < postorderSize; i++) {
        if (postorder[i] < postorder[postorderSize - 1]) {
            return false;
        }
    }
    //递归分治。判断 左子树 与 右子树 是否成立。
    return (verifyPostorder(postorder, seprate) && verifyPostorder(postorder + seprate, postorderSize - seprate - 1));
}
```
