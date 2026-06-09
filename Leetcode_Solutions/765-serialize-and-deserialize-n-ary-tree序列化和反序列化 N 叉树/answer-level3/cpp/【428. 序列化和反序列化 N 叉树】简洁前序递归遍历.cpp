## 思路一：前序递归遍历
### 代码
```c++
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        if (!root) {
            s = "#";
            return s;
        }
        s = to_string(root->val) + " " + to_string(root->children.size()); 
        for (const auto &child : root->children) {
            s = s + " " + serialize(child);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream is(data);
        return DFS(is);
    }

    Node* DFS(istringstream &is) {
        string s, size;
        is >> s;
        if (s == "#") return nullptr;
        is >> size;
        Node *p = new Node(stoi(s));
        for (int i = 0; i < stoi(size); ++i) {
            p->children.push_back(DFS(is));
        }
        return p;
    }
};
```
