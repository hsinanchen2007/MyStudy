C++ 0ms 双100%
简单易懂，看注释

```
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int d = log(label)/log(2) + 1; // 求深度
        vector<int> ans;
        ans.push_back(label);

        while(--d)
        {
            int root = label / 2; // 找到原始父节点的编号
            int start = pow(2, d - 1); // 计算每层开始的编号和结束的编号
            int end = pow(2, d) - 1;
            ans.push_back(start + end - root); // 找到现在父节点的编号
            label = start + end - root;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```
