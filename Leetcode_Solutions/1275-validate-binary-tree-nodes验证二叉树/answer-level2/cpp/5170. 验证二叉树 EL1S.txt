正常二叉树，-1加和是 n + 1
```
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int sum = 0;
        for(auto x: leftChild)
        {
            if(x == -1) sum++;
        }
        for(auto x: rightChild)
            if(x == -1) sum++;
        return sum == n + 1;
    }
};
```
