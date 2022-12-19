二叉搜索树左子树的值比根小，右子树的值比根大
后续遍历最后一个数就是跟，然后从左往右遍历，找到第一个比跟大的元素，这个元素左边就是左子树，右边就是右子树，对左右子树进行同样的判断
同时要保证左子树的值比跟小，右子树的值比跟大
```
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
         return help(postorder,0,postorder.size()-1);
    }
    bool help(vector<int>& postorder,int first,int last)
    {
        if(first>last) return true;
        int i=first;
        while(postorder[i]<postorder[last]) i++;
        int m=i;
        while(postorder[i]>postorder[last]) i++;

        return i==last&&help(postorder,first,m-1)&&help(postorder,m,last-1);
    }
};
```
