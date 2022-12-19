都是带佬，没有想到位运算表示label，但是找到了对应的转换公式
label在当前层的位置为pos，则在上一层对应的节点为`label-pos-(pos-1)/2`，其中`(pos-1)/2`是因为是二叉树。
还有一个点是倒序处理的，从叶子向上递推。
```
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log2(label)+1;
        vector<int> ans;
        ans.push_back(label);
        while(level!=1){
            int pos = label-pow(2,level-1)+1;
            label = label-pos-(pos-1)/2; // 计算在level层的位置
            level--;
            ans.push_back(label);
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
在取对数和计算幂上费时，但是结果还是时间内存超100%/100%。