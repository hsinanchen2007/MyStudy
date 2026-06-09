### 解题思路
递归

### 代码

```cpp

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        function<void(Node*)> dfs = [&res, &dfs](Node* node){
            if (node == nullptr) {
                res += " ";
                return;
            }
            res += to_string(node->val);
            res += "[";
            for (auto e : node->children) {
                dfs(e);
            }
            res += "]";
        };
        dfs(root);
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int n = data.size();
        function<Node*(int&)> dfs = [n, &data, &dfs](int& pos)->Node*{
            if (data[pos] == ' ') {
                pos++;
                return nullptr;
            }
            int sign = data[pos] == '-' ? (pos++, -1) : 1;
            int val = 0;
            while (isdigit(data[pos])) {
                val = val * 10 + data[pos] - '0';
                pos++;
            }
            Node* node = new Node(sign * val);
            pos++; // '['
            while (data[pos] != ']') {
                node->children.push_back(dfs(pos));
            }
            pos++; // ']'
            return node;
        };
        int pos = 0;
        return dfs(pos);
    }
};

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```