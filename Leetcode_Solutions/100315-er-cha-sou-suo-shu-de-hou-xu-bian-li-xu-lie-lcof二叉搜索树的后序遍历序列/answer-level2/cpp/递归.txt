### 解题思路
/*
后序遍历的特点：根几点在最后：
若数组是二叉搜索树的后序遍历，则数组特点：根节点将数组分成左右两部分，左边小于根节点，右边大于根节点， 
递归判断左右两半即可
*/

### 代码

```cpp

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        bool result = true;
        int size = postorder.size();
        if (size <=1)  return result;
        return help(postorder, 0, size -1);

    }

    bool help(vector<int>& postorder, int start, int end) {
        if (start > end) return true;
        int post = postorder[end];
        int index = start;
        while(index< end && postorder[index] <= post) {
            index ++;
        }
        index--;
        int mid  = index;
        for (auto  i = index+1;i < end; i++) {
            if (postorder[i] < post) return false;
        }
        return help(postorder, start, mid) && help(postorder, mid+1, end-1);

    }
};
```