### 解题思路
1...n组成的二叉树总数，即为分别以1...n为根的二叉树的总个数。每种相同根的二叉树个数等于左子树的种类树乘以右子树的种类树。
由于二叉搜索树中左子树的节点值永远比根小，右子树的节点值永远比根大，所以i的左子树种类数等于以1..i-1为节点组成的二叉搜索树种类数，i的右子树种类数等于以i+1..n为节点组成的二叉搜索树种类数，等于1..n-i为节点组成的二叉搜索树种类数。
即result[i]=result[i-1]*result[n-i]，循环递推可得出结果。

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> result;
        int count;
        result.push_back(1);
        result.push_back(1);
        for(int i=2;i<=n;i++){
            count=0;
            for(int j=1;j<=i;j++){
                count+=result[j-1]*result[i-j];
            }
            result.push_back(count);
        }
        return result[n];
    }

};
```