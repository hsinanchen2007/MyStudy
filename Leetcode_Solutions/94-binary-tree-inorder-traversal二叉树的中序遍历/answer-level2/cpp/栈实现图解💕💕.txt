### ✨ 思路 ：
这里回退到上一个父节点的操作体现了 “栈” 的思想

<![image.png](https://pic.leetcode-cn.com/2570cf503e6b0bfa10b9b6b461971b804350689693cf9268f4f8491b2deb289a-image.png), ![image.png](https://pic.leetcode-cn.com/5e06e66f11c08b661c1fef6e2be9cbfc90d1dde308f4b13211d37f457479d02b-image.png),![image.png](https://pic.leetcode-cn.com/bfc95e7995b2b982b47e80fb62f98830fb7031ba1a0a4006824418f03dcaace3-image.png),![image.png](https://pic.leetcode-cn.com/50e1a3055fa6a32b8f4d564e3b5961fc4b19a748ad69b5f7cb84df6153eb6090-image.png),![image.png](https://pic.leetcode-cn.com/9a7fc5c814ea5ca49d4db0e521c639b9dbec68012780220e51b9d1a383fc0cb9-image.png),![image.png](https://pic.leetcode-cn.com/9bf3eeb5b0ea1322694380c60f476f86cf73cf59d6f64e36d95f8a663626009a-image.png),![image.png](https://pic.leetcode-cn.com/5942f474ac495c4156917a48bee521fcfaab1e1170c627a0853417900abfb581-image.png),![image.png](https://pic.leetcode-cn.com/aacfc51e35df818067992c4645e5c9b8410623c157c491a2091227beb55884fc-image.png),![image.png](https://pic.leetcode-cn.com/1a3a948d3fba10f37331fc328c9ed6245edc3dc0974535567c712ac9addabd0c-image.png),![image.png](https://pic.leetcode-cn.com/2e670c3a153eae50af0e1db4b2751cf5282bb19aadcbd9bb5997e1c07f5fdc71-image.png),![image.png](https://pic.leetcode-cn.com/1d8b6d6c524087ea508774291360725f79c3e94940e75bda480c0cb6d7e51841-image.png),![image.png](https://pic.leetcode-cn.com/d26adfd2eb97214dbcf83a984dbf6f6fedd2ed8e858bbed0562b156ecfee77eb-image.png),![image.png](https://pic.leetcode-cn.com/e50b405ab2805823e68c37c0879bcf52e06d31454a79a07df265a68344164709-image.png),![image.png](https://pic.leetcode-cn.com/f627b10c7a269d2f3f74e95a2b0d550a26558e62c32c134e228241c28525a910-image.png),![image.png](https://pic.leetcode-cn.com/ebb77be355dcaaf68cc611f6dd4016a666f8e3d3489b95d0116371c300d63463-image.png)>


```
class Solution {
public:
    // 中序遍历：左中右
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode *> s;
        vector<int> ans;
        while(p || !s.empty()) {
            if(p) { // 只要左节点非空就一直一直向左，找到最左边的节点，并把这一路遇到的节点依次入栈
                s.push(p);
                p = p->left;
            } else { // 从最左边的节点开始依次出栈，回退到上一个节点时访问其右子树
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;       
    }
};
```

### ✨ 复杂度分析
每个节点各入栈，出栈一次，时间复杂度为 O(n)
