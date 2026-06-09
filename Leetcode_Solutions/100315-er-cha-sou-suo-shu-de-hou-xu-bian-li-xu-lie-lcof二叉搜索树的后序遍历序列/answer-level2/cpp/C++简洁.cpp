```
class Solution {
public:
    bool judge(vector<int> &postorder, int left, int right){
        if(left > right)    return true; //空树返回true
        int index = left;
        while(index < right && postorder[index] < postorder[right]) index++;  //找到右子树第一个节点index
        for(int i = index; i < right; ++i){        //遍历右子树，若有比根节点小的返回false
            if(postorder[i] < postorder[right])
                return false;
        }
        return judge(postorder, left, index - 1) && judge(postorder, index, right - 1); //递归判断左右子树
    }

    bool verifyPostorder(vector<int>& postorder) {
        return judge(postorder, 0, postorder.size() - 1);
    }
};
```