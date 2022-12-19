BFS，层序遍历，类似二叉树最大深度

代码：
```
class Solution {
public:
    int maxDepth(Node* root) {
        vector<Node*> v;
        int ans = 0;
        if (root)
            v.push_back(root);
        while (!v.empty()) {
            ans++;
            int num = v.size();
            while (num) {
                int child = v[0]->children.size();
                for (int i = 0; i < child; i++) {
                    if (v[0]->children[i])
                        v.push_back(v[0]->children[i]);
                }
                v.erase(v.begin());
                num--;
            }
        }
        return ans;
    }
};
```
