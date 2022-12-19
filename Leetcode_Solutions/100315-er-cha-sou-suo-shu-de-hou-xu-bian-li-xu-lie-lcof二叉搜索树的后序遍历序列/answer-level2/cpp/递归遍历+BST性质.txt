### 解题思路
此处撰写解题思路
每一个数组最后一个节点一定是当前子数组的根结点，通过BST的性质进行数值比较，一直递归到左右index相等，返回
### 代码

```cpp
class Solution {
public:
bool recursiveTraverse(vector<int>& postOrder, int left, int right){
        if(left >= right){
            return true;
        }
        int index = left;
        int rootVal = postOrder.at(right);

        for(index = left; index < right; index++){
            if(postOrder.at(index) > rootVal){
                break;
            }
        }
        for(int i = left; i < index; i++){
            if(postOrder.at(i) > rootVal){
                return false;
            }
        }
        for(int j = index; j < right; j++){
            if(postOrder.at(j) < rootVal){
                return false;
            }
        }


        if(recursiveTraverse(postOrder, left, index -1) && recursiveTraverse(postOrder, index, right - 1)){
            return true;
        }
        else{
            return false;
        }
  

    }

    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()){
            return true;
        }
        return recursiveTraverse(postorder, 0, postorder.size() - 1);
    }
    
};
```