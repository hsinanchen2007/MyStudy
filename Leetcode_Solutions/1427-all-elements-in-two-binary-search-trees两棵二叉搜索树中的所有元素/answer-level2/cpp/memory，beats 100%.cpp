中序+归并，理论上应该是最容易想到的解，大家也有很多ac的实现。
但数组归并需要额外两个数组O(n)的空间，对大数据量的场景下，内部不友好。
因此，这里特意贴一个O(1)内存的AC代码，等价于：对两个树直接做归并排序，有兴趣的可以参考下。
```
class Solution {
public:
    vector<int> ans;

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        TreeNode* curr1 = root1;
        TreeNode* curr2 = root2;
        stack<TreeNode*> s1, s2;

        // 首次定位
        while (curr1 && curr1->left) {
            s1.push(curr1);
            curr1 = curr1->left;
        }
        while (curr2 && curr2->left) {
            s2.push(curr2);
            curr2 = curr2->left;
        }

        // 归并排序
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                ans.push_back(curr1->val);

                if (!curr1->right) {
                    if (s1.empty()) {
                        curr1 = nullptr;
                        break;
                    }
                    curr1 = s1.top();
                    s1.pop();
                } else {
                    curr1 = curr1->right;
                    while (curr1->left) {
                        s1.push(curr1);
                        curr1 = curr1->left;
                    }
                }
            } else {
                ans.push_back(curr2->val);

                if (!curr2->right) {
                    if (s2.empty()) {
                        curr2 = nullptr;
                        break;
                    }
                    curr2 = s2.top();
                    s2.pop();
                } else {
                    curr2 = curr2->right;
                    while (curr2->left) {
                        s2.push(curr2);
                        curr2 = curr2->left;
                    }
                }
            }
        }
        // 这里没有想到太好的解法
        if (curr1) {
            inorder(root1, curr1);
        } else {
            inorder(root2, curr2);
        }

        return ans;
    }

    void inorder(TreeNode* root, TreeNode* pivot) {
        bool willPut = false;

        TreeNode* curr = root;
        stack<TreeNode*> s;
        while (curr) {
            while (curr->left) {
                s.push(curr);
                curr = curr->left;
            }
            if (curr == pivot) {
                willPut = true;
            }
            if (willPut) {
                ans.push_back(curr->val);
            }
            while (curr->right == nullptr) {
                if (s.empty()) {
                    break;
                }
                curr = s.top();
                s.pop();
                if (curr == pivot) {
                    willPut = true;
                }
                if (willPut) {
                    ans.push_back(curr->val);
                }
            }
            curr = curr->right;
        }
    }
};
```
