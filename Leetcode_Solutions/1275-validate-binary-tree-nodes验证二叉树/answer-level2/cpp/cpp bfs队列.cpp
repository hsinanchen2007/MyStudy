### 解题思路
创建queue数组存放从根至叶的所有结点，非空结点则存其左右孩子，空则跳过，最后检查是否有交叉或环

### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int *container=new int[n]{0};
        vector<int> queue;
        queue.push_back(0);
        int i=0;//队列指针
        int poi=0;//Child数组指针
        while (i<queue.size() and poi<leftChild.size()){
            if (queue[i]!=-1){//结点非空，压左右孩子（包括空结点）
                queue.push_back(leftChild[poi]);
                queue.push_back(rightChild[poi]);
                poi++;
            }
            i++;
        }
        if (poi<leftChild.size()) return false;//提前退出，说明至少2棵树
        for (int i=0;i<queue.size();i++){
            if (queue[i]!=-1)
                container[queue[i]]++;
        }
        for (int i=0;i<n;i++){
            if (container[i]>1) return false;//从根开始遍历不应该出现相同结点
        }
        return true;
    }
};
```