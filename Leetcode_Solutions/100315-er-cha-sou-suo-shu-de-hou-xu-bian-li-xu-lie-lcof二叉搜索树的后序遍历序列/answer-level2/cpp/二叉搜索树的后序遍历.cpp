### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size();
        if(!len) return true;
        int root = postorder[len-1];
        //左子树比根节点小
        int i = 0;
        for(;i < len-1;i++){
            if(postorder[i] > root)
                break;
        }
        //右子树比根节点大
        for(int j = i;j < len-1;j++){
            if(postorder[j] <= root)
                return false;
        }
        bool right=true,left=true;
        if(i>0) {
            vector<int>temp(postorder.begin(),postorder.begin()+i);
            right = verifyPostorder(temp);
        }
        if(i<len-1){
            vector<int>temp(postorder.begin()+i,postorder.begin()+len-1);
            left = verifyPostorder(temp);
        }
        return right&&left;
    }
};
```