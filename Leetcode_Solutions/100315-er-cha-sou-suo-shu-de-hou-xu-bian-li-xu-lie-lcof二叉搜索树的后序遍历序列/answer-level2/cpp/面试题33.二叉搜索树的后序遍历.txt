### 解题思路
核心思路：判断某序列是否为搜索二叉树的后序遍历序列，调用递归函数recur，recur中从头至尾遍历，检测是否符合【都小于最后一个（左子树），都大于最后一个（右子树），最后一个】的形式，然后递归检查左右子树
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder,0,postorder.size()-1);
    }
    bool recur(vector<int>& postorder,int i,int j){
        if(i>=j)return true;
        int l=i;
        while(postorder[l]<postorder[j])l++;
        int m=l;
        while(postorder[l]>postorder[j])l++;
        return l==j&&recur(postorder,i,m-1)&&recur(postorder,m,l-1);
    }
};
```