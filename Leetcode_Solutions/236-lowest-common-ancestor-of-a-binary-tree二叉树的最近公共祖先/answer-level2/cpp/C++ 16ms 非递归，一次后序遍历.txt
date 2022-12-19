非递归的后续遍历需要用栈来辅助，而遍历过程中栈中正好保存了从该节点到跟的路径。
在遍历过程中，发现其中一个节点时，标记栈中所有元素。
再发现另一个节点时，找栈中剩下的被标记元素。
这里把标记位藏到指针低位了，顺便把后续遍历中用来标记是否访问过的标记位也藏在这。

```cpp
class Solution {
    typedef TreeNode *Node;
    static inline intptr_t as_int(Node p) {
        return reinterpret_cast<intptr_t>(p);
    }
    static inline Node get_ptr(Node p) {
        return reinterpret_cast<Node>(as_int(p) & ~static_cast<intptr_t>(3));
    }
    static inline Node set_flag(Node p, intptr_t flag) {
        return reinterpret_cast<Node>(as_int(p) | flag);
    }
    static inline bool get_flag(Node p, intptr_t mask) {
        return (as_int(p) & mask) != 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p != q) {
            vector<Node> s;
            auto x = root;
            auto flag = true;
            s.reserve(512);
            while(x || !s.empty()) {
                while(x) {
                    s.push_back(x);
                    x = x->left;
                }
                if(!s.empty()) {
                    auto &top = s.back();
                    x = get_ptr(top);
                    if(get_flag(top, 1)) {
                        // visit x
                        if(x == p || x == q) {
                            if(flag) {
                                for_each(s.begin(), s.end(), [](Node &e) {
                                    e = set_flag(e, 2);
                                });
                                flag = false;
                            } else {
                                auto i = find_if(s.begin(), s.end(), [](const Node &e){
                                    return !get_flag(e, 2);
                                });
                                return get_ptr(*(--i));
                            }
                        }
                        s.pop_back();
                        x = nullptr;
                    } else {
                        top = set_flag(top, 1);
                        x = x->right;
                    }
                }
            }
        }
        return p;
    }
};
```