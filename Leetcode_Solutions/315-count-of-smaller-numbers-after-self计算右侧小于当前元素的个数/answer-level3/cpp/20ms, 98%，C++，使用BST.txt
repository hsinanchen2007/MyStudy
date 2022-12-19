```
![屏幕快照 2019-07-12 下午3.35.41.png](https://pic.leetcode-cn.com/9773a46cf306f7d3c0b7889b6dd2a754670e86fa341b06a1a8c004b998f74ccd-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-12%20%E4%B8%8B%E5%8D%883.35.41.png)
// 树节点
class TNode {
public:
    int val;            // 数字值
    int count;          // 左子树（包括根节点自身）的总节点数，默认是1
    int com;            // 相同值的重复数
    TNode* pLeft;       // 左子节点
    TNode* pRight;      // 右子节点
    TNode(int v)
        : val(v), count(1), com(1), pLeft(nullptr), pRight(nullptr) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size(); if (n < 1) return vector<int>();
        vector<int> res(n);
        TNode* root = new TNode(nums[n - 1]);
        res[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            res[i] = createTree(root, nums[i]); // 按原数组从左到右的顺序构建二叉树
        }    
        return res;
    }
    
    // 按原数组从左到右的顺序构建二叉树
    // 函数返回要插入 val 的结果（即其对应的 count 值）
    int createTree(TNode* pCur, int val) {
        if (val > pCur->val) {  // 右转, res += 当前节点的 count 值
            if (pCur->pRight) return createTree(pCur->pRight, val) + pCur->count;
            else {
                pCur->pRight = new TNode(val);
                return pCur->count;
            }
        } else if (val < pCur->val) {   // 左转，当前节点的 count 值 ++
            pCur->count++;
            if (pCur->pLeft) return createTree(pCur->pLeft, val);
            else {
                pCur->pLeft = new TNode(val);
                return 0;
            }
        } else {    // 相等，看作左转，不建立新节点，当前节点的 count 值 ++，注意记录重复值
            return (++pCur->count) - (++pCur->com);
        }
    }
};
```
![屏幕快照 2019-07-12 下午3.35.41.png](https://pic.leetcode-cn.com/0f3916c84f9de3e099e48f87a8fba8cd43c5515080b745cce22b786c9d90f319-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-12%20%E4%B8%8B%E5%8D%883.35.41.png)
