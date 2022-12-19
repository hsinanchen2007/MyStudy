多的不说，都在注释里了
```
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);       // 第一层入队
        q.push(nullptr);    // 空指针作为层分隔符
        int find = 0;       // 记录找到的符合条件的元素个数
        while (!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            if (!p) {                   // 空指针表示本层遍历完毕
                if (q.empty()) break;   // 没有下一层了
                if (find == 1) break;   // 在本层只找到一个符合条件的节点
                q.push(nullptr);        // 添加层分隔标志
            } else {
                if (p->val == x || p->val == y)     // 元素符合条件
                    if (++find == 2) return true;   // 本层找到两个
                
                if (p->left && p->right) {      // 子节点入队之前，先要检查x,y是否为亲兄弟
                    if (p->left->val * p->right->val == x * y &&    
                        p->left->val + p->right->val == x + y)
                        return false;           // 相乘和相加的结果都一样，说明两组数是相同的
                }
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        return false;
    }
};
```
