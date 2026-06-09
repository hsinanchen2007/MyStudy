### 解题思路
C++,递归判断数组是不是可以被最后一位分成小于和大于它的两部分

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0) return true;
        return is_ok(postorder, 0, postorder.size() - 1);
    }
    bool is_ok(vector<int>& postorder, int l, int r){
        bool flag = false;
        int mid = l;
        if(l == r) return true;
        for(int i=l; i<r; i++){
            if(postorder[i] > postorder[r] && !flag) {
                flag = true;
                mid = i;
            }
            if(flag && postorder[i] < postorder[r]) return false;
        }
        if(mid == l) return is_ok(postorder, mid, r - 1);
        else return is_ok(postorder, l, mid - 1) && is_ok(postorder, mid, r - 1);
    }
};
```