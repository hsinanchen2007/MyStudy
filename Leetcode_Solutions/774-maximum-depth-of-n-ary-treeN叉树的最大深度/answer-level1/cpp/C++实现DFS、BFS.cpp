```
class Solution {
public:
    // 第一种： 递归
    int maxDepth1(Node* root) {
        if (!root) return 0;

        int depth = 0;
        for (Node *node : root->children) {
            depth = max(depth,maxDepth(node));
        }

        return ++depth;
    }

    // 第二种: BFS 直接利用层级遍历返回depth
     int maxDepth2(Node* root) {
        if (!root) return 0;

        int depth = 0;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            depth ++;
            int size = q.size();
            while(size--) {
                Node *node = q.front();
                q.pop();

                for (Node* n : node->children) {
                    if (n) q.push(n);
                }
            }
        }

        return depth;
     }

        // 第三种：DFS
        int maxDepth(Node* root) {
            if (!root) return 0;

            int depth = 1;
            stack<pair<Node*, int>> st;
            st.push(make_pair(root, 1));

            while (!st.empty()) {
                pair<Node*,int> p = st.top();
                st.pop();
                Node *node = p.first;
                int d = p.second;
                depth = max(depth,d);

                for (Node* n : node->children) {
                    if (n) st.push(make_pair(n, d+1));
                }
            }

            return depth;
        }
};

```
