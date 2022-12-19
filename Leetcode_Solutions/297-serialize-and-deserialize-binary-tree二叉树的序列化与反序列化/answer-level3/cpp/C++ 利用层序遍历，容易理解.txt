# 序列化
层序遍历，空节点存储为#,非空节点存储值再加一个！，方便反序列化的时候将节点值分割出来。
比如[2,1,3]，存储为"2!1!3!####"。这样二叉树与映射字符串一一对应。
具体实现代码如下：
```
string serialize(TreeNode* root) {
    string str;
    if(root == nullptr) return str;
    queue<TreeNode*> queue;
    queue.push(root);
    
    while(!queue.empty()){
        int count = queue.size();
        while(count--){
            TreeNode* node = queue.front();
            queue.pop();
            if(node == nullptr)   
                str += "#";
            else{
                str += to_string(node->val) + "!";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
    }
    
    return str;
}
```
# 反序列化
当然也是层序构建，根据！将节点值分割出来，#则建立空节点。
针对非空节点需要建立左右节点，而空节点直接跳过。
实现起来也不难
```
TreeNode* deserialize(string data) {
    if(data.empty())    return NULL;
    int i =0, j=0;
    while(j<data.size() && data[++j]!='!') ;    // [i, j) 存储节点
    TreeNode* head = new TreeNode(stoi(data.substr(i, j-i)) );
    
    queue<TreeNode*> queue;
    queue.push(head);
    
    while(i < data.size()){
        TreeNode* node = queue.front();
        queue.pop();
        if(node == NULL)    continue;
        // 左节点
        i = ++j;
        if(i >= data.size())    break;
        if(data[i] == '#')
            node->left = nullptr;
        else{
            while(j<data.size() && data[++j] != '!');
            node->left = new TreeNode(stoi(data.substr(i, j-i)) );
        }
        queue.push(node->left);
        // 右节点
        i = ++j;
        if(i >= data.size())    break;
        if(data[i] == '#')
            node->right = nullptr;
        else{
            while(j<data.size() && data[++j] != '!');
            node->right = new TreeNode(stoi(data.substr(i, j-i)) );
        }
        queue.push(node->right);
    }
    
    return head;
}
```
是不是很容易理解，速度也不错。
代码哪里还有优化的地方，欢迎大家提出建议。