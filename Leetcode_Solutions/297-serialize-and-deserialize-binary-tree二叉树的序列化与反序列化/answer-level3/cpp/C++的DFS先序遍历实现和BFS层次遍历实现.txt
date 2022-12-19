> 开始想用先序后序两种遍历结果恢复二叉树，结果发现存在重复出现的元素，根本行不通
> 记录一下，实现的两种方法

- 协议的格式很简单，就是将元素写入string中，并按照空格键分割

##### 先序遍历（递归实现）
```C++
void help(string &ret, TreeNode *root) {
    if (!root) {
        ret += "null ";
        return;
    }
    ret += to_string(root->val) + " ";
    help(ret, root->left);
    help(ret, root->right);
}

string Codec:: serialize(TreeNode *root) {
    string ret;
    if (!root) return ret;
    // 按先序遍历递归完成序列化
    help(ret, root);
    return ret;
}

TreeNode *help(queue<string>& q) {
    if (q.empty()) return nullptr;
    string rootval = q.front();
    q.pop();
    if (rootval == "null") return nullptr;
    TreeNode *root = new TreeNode(stoi(rootval));
    root->left = help(q);
    root->right = help(q);
    return root;
}

TreeNode *Codec::deserialize(string data) {
    if (data.empty()) return nullptr;
    queue<string> q;
    string str;
    istringstream input(data);
    while (input >> str) q.push(str);
    return help(q);
}

```


##### 层次遍历实现（迭代实现）
```C++
string Codec::serialize(TreeNode *root) {
    if (!root) return "";
    queue<TreeNode *> q;
    q.push(root);
    string ret;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node) {
            q.push(node->left);
            q.push(node->right);
            ret += to_string(node->val) + " ";
        } else {
            ret += "null ";
        }
    }
    return ret;
}

TreeNode *Codec::deserialize(string data) {
    if (data.empty()) return nullptr;
    queue<string> elems;
    istringstream input(data);
    string str;
    while (input >> str) elems.push(str);
    // 层次遍历构建树时，需要知道当前节点的根结点，因此需要用辅助数据结构保存之前构建好的根
    // 这里使用一个队列来保存之前构建好的可能是之后的元素的根的节点
    queue<TreeNode *> help;
    // 先构建整棵树的根
    str = elems.front(); elems.pop();
    TreeNode *root = new TreeNode(stoi(str));
    help.push(root);
    while (!elems.empty()) {
        TreeNode *node = help.front();
        help.pop();
        // 从elems中获取当前node的左儿子 
        str = elems.front(); elems.pop();
        if (str != "null") {
            TreeNode *child = new TreeNode(stoi(str));
            node->left = child;
            help.push(child);
        }
        // 获取右儿子
        if (elems.empty()) break;
        str = elems.front(); elems.pop();
        if (str != "null") {
            TreeNode *child = new TreeNode(stoi(str));
            node->right = child;
            help.push(child);
        }
    }
    return root;
}

```
