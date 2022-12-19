### 解题思路
postorder最后的一个元素是根元素，从根元素往前找到比根元素小的第一个值，记录引索i，然后从此处继续往前遍历，判断一下是否有大于等于根元素的值，有的话，直接返回false。
否则的话，从i处将剩余节点分成左右子树的后续遍历，继续递归求解。

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() <= 1) {
            return true;
        }
        auto root = postorder.back();
        long i = postorder.size() - 2;
        while (i>=0 && postorder[i] > root) {
            i--;
        }
        
        long l = i;
        while (l >=0) {
            if (postorder[l] >= root) {
                return false;
            }
            l--;
        }
        vector<int> left = vector<int>(postorder.begin(), postorder.begin() + i + 1);
        auto right = vector<int>(postorder.begin() + i + 1, postorder.end() - 1);
        return verifyPostorder(left) && verifyPostorder(right);
    }
};
```