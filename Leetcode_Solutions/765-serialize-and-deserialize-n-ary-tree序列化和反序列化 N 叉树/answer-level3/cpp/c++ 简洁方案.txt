前序遍历生成字符串，栈迭代生成树
```
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == NULL)
            return "";
        string res = to_string(root->val) + "[";
        for (auto node : root->children) {
            res += serialize(node) + ",";
        }
        if (res.back() == ',')
            res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        cout << data << endl;
        string value;
        Node* head = NULL;
        stack<Node*> s;
        for (int i = 0; i < data.size(); ++i) {
            const char& c = data[i];
            if ((c >= '0' && c <= '9') || c == '+' || c == '-') {
                value += c;
            } else if (c == '[') {
                Node* node = new Node(stoi(value));
                if (head == NULL)
                    head = node;
                s.push(node);
                value.clear();
            } else if (c == ']') {
                Node* node = s.top();
                s.pop();
                if (!s.empty()) {
                    Node* prev_node = s.top();
                    prev_node->children.push_back(node);
                }
            }
        }
        return head;
    }
};
```
 ![image.png](https://pic.leetcode-cn.com/87ae117480e61ce7c383385f7c3a33a06c5a3efd88dabd2dfa424170c9844521-image.png)
