序列化的样式类似于json， 像:
1{2{3, 2}, 4{,5}}
右值前面有一个逗号

bfs的超时了。。。

因为一开始没考虑负数。。。
所以负数部分加的有点丑。。。
当然其他部分也不好看。。。

```

int to_int(const std::string &str) {
    int tar = 0;
    int sign = 1;
    for (auto c : str) {
        if (c == '-') {
            sign = -1;
            continue;
        }
        if (c > '9' and c < '0')
            continue;
        tar = (c - '0') + tar * 10;
    }
    return tar * sign;
}

std::string i2string(int num) { // 本来叫to_string, 然后莫名其妙冲突了。。。
    int i = num > 0 ? num : -num;
    if (i == 0)
        return "0";
    std::string tar;
    while (i != 0) {
        tar += (i % 10) + '0';
        i /= 10;
    }
    if (num < 0) {
        tar.push_back('-');
    }
    std::reverse(tar.begin(), tar.end());
    return tar;
}

class CodecDfs {
public:
    string serialize(TreeNode *root) {
        std::string values;
        serialize(root, values);
        return values;
    }

    void serialize(TreeNode *root, std::string &values) {
        if (root) {
            values += i2string(root->val);
            if (root->left or root->right) {
                values += "{";
                if (root->left) {
                    serialize(root->left, values);
                }
                if (root->right) {
                    values += ",";
                    serialize(root->right, values);
                }
                values += "}";
            }
        }
    }

    TreeNode *deserialize(string data) {
        if (data == "")
            return nullptr;
        TreeNode *root = new TreeNode(0);
        int index = 0;
        deserialize(data, index, root);
        return root;
    }

    bool is_digtal(char c) { return c == '-' or c >= '0' and c <= '9'; }

    int get_int(const std::string &data, int &index) {
        std::string num_str;
        while (is_digtal(data[index])) {
            num_str += data[index];
            ++index;
        }
        return to_int(num_str);
    }

    void *deserialize(const std::string &data, int &index, TreeNode *cur) {
        int num = get_int(data, index);
        cur->val = num;
        if (data[index] == '{') {
            ++index;
            if (is_digtal(data[index])) {
                cur->left = new TreeNode(0);
                deserialize(data, index, cur->left);
            }
            if (data[index] == ',') {
                ++index;
                cur->right = new TreeNode(0);
                deserialize(data, index, cur->right);
            }
            if (data[index] == '}')
                ++index;
        }
    }
};

```