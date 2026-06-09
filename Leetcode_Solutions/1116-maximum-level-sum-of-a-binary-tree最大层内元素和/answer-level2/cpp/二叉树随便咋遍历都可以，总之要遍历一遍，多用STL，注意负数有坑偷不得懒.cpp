```

class Solution {
    long int maximal = -1e5;
    int minlayer = 1;
    map<int, long int> layerSum;
    void travelTree(TreeNode* root, int layer) {
        if (root == nullptr) return;
        if (layerSum.count(layer) == 0) layerSum[layer] = 0;
        layerSum[layer] += root->val;
        // if (maximal < layerSum[layer]) { // 由于存在负数不能直接这样取值
        //     minlayer = layer;
        //     maximal = layerSum[layer];
        // }
        travelTree(root->left, layer + 1);
        travelTree(root->right, layer + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        travelTree(root, 1);
        minlayer = max_element(layerSum.begin(),layerSum.end(), 
            [](const pair<int, long int> &a, const pair<int, long int> &b){return a.second < b.second;})->first;
        return minlayer;
    }
};
```
