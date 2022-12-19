```
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        vector<int> left, right;
        int root = postorder.back();
        int i = 0;
        for(; i<postorder.size()-1; i++) {
            if(postorder[i] < root)
                left.push_back(postorder[i]);
            else
                break;
        }
        int j = i;
        for(; j<postorder.size()-1; j++) {
            if(postorder[j] > root)
                right.push_back(postorder[j]);
            else
                return false;
        }
        bool le = true, ri = true;
        // 当i=0时，只有右子树
        if(i > 0) le = verifyPostorder(left);
        // 当i=postorder.size() - 1时，只有左子树
        if(i < postorder.size() - 1) ri = verifyPostorder(right);
        return le && ri;
    }
};
```
