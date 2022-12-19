```c++
class Solution {
	map<int, bool> m;
	map<int, Node *> p;
public:
    Node* cloneGraph(Node* node) {
    	if (m[node->val] == true) return p[node->val];
        Node *node_cpy = new Node(node->val);
        m[node->val] = true;
        p[node->val] = node_cpy;
		for (int i = 0; i < node->neighbors.size(); ++i) {
			Node * neighbor = node->neighbors[i];
			Node *cur_nb = cloneGraph(neighbor);
			node_cpy->neighbors.push_back(cur_nb);
		}
		return node_cpy;
    }
};