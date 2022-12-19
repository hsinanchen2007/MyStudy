### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        //主要思想，根节点在最右边，左边以不分应该小于根节点，右边一部分应该大于根节点
        //递归调用
       return  helper(postorder,0,postorder.size()-1);
    }
    bool helper(vector<int>& postorder,int left,int right){
        if(left>=right) return true;
        int root=postorder[right];
        int cleft=left;
        while(postorder[cleft]<root&&cleft<right)
            cleft++;
        int cright=cleft;
        while(postorder[cright]>root&&cright<right)
            cright++;
        if(cright!=right) return false;
        return helper(postorder,left,cleft-1)&&helper(postorder,cleft,cright-1);
    }
};
```