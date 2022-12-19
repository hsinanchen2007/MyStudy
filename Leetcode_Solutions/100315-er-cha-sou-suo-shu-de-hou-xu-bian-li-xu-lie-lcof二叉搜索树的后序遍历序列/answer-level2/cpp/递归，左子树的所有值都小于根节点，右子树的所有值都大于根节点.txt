### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())return true;  //否则有个样例无法通过
        return verifyPostorder(postorder, 0, postorder.size()-1);
    }
    bool verifyPostorder(vector<int> &postorder, int begin, int end)
    {
        //end表示当前子树的根节点下标
        if(postorder.empty() || begin > end)return false;
        //从前往后找到左右子树的分界点
        int i = begin;  //从i=begin开始
        while(i < end)
        {
            if(postorder[i] > postorder[end])  //若第i个数大于根节点，则说明第i个数是右子树的
                break;
            ++i;
        }
        //此时的i是左右子树的分界点，从i开始往后是右子树
        //判断右子树的每个数是否都大于根节点
        int j = i;
        while(j < end)
        {
            if(postorder[j] <= postorder[end])
                return false;  //右子树不大于根节点，返回false
            ++j;
        }
        bool left = true;  //左子树是二叉搜索树，i有可能就还是begin，且i==end，那表示i就是根节点
        if(i > begin)  //i>begin，说明i是第一个大于postorder[end]的节点
            left = verifyPostorder(postorder, begin, i - 1);  //左子树递归
        bool right = true;
        if(i < end - 1)  //i是属于右子树的
            right = verifyPostorder(postorder, i, end - 1);  //右子树递归
        return left && right;
    }
};
```