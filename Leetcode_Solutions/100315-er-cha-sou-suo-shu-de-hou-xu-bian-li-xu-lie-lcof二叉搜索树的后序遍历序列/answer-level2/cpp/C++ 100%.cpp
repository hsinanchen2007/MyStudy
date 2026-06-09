### 解题思路
后续遍历最后一个为根节点

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if(n <= 2) return true;
        return helper(postorder, 0, postorder.size()-1);
    }

    bool helper(vector<int>& postorder, int left, int right) {
        if(left>=right) return true;
        int mid=left;
        for(; mid<right; ++mid){
            if(postorder[mid] > postorder[right]) break;
        }
        for(int i = mid+1; i<=right; ++i) {
            if(postorder[i] < postorder[right]) return false;
        }
        return helper(postorder, left, mid-1) && helper(postorder, mid, right-1);
    }
};
```