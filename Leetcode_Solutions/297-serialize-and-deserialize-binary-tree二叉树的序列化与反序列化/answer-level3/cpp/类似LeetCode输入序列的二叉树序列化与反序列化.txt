### 解题思路
这个方法中的序列化结果与LeetCode中的二叉树样例是一样的（形如[5,2,3,null,null,2,4,3,1]），只不过题目要求输出是string，所以在反序列化时会有一个转化为vector的过程。

所以题目就变为了如何根据一个LeetCode的二叉树序列重新生成二叉树。


从样例来看，LeetCode的生成是BFS，即一层一层生成的。而值得注意的是，每一个节点都是有效节点，即拥有父节点的节点。有效节点这个概念是我自己定义的，方便后面的解题过程。

所以复现二叉树的想法也是，根据序列找到每一层的所有有效节点，将其与下一层的有效节点连接起来。最后一层就不用处理它们的子节点了。

具体的方法可以参考代码里的注释。

### 代码

```cpp
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp) {
                    s += to_string(tmp->val) + " ";
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                else s += "n ";
            }
        }
        while (s.back() < '0' || s.back() > '9') s.pop_back();  //把最后一个有效非空节点后面的字符全部删掉
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<TreeNode*> num;
        //将字符串处理为vector存储的节点，这里的节点均为有效节点
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == 'n') {
                num.emplace_back(nullptr);
                i++;
            }
            else {
                int cur = i;
                while (i < data.size() && data[i] != ' ') i++;
                auto *node = new TreeNode(atoi(data.substr(cur, i - cur).c_str()));
                num.push_back(node);
            }
        }

        int count = 0;  //count 代表当前层数
        int layer = 1;  //layer 代表某一层有多少个有效节点
        int last;       //last  代表当前层有多少个有效节点为空节点
        vector<int> end;    //存储每一层的结束位置，值为当前层最后一个节点的后一个位置
        while (count + layer < num.size()) {
            last = 0;
            for (int i = count; i < count + layer; ++i) {
                if (!num[i]) last++;
            }
            end.push_back(count + layer);
            count += layer;
            layer -= last;
            layer *= 2;
        }
        end.push_back(num.size());  //这里为了最后遍历时不越界，加上最后一层的结束位置，也就是num的长度
        int pos;    //用于记录下一层的有效节点的原始坐标
        last = 0;   //用于记录当前层的开始位置
        for (int i = 0; i + 1 < end.size(); ++i) {
            pos = end[i];    //指向下一层的开始位置
            for (int j = last; j < end[i]; ++j) {
                if (num[j]) {
                    //如果有效节点不为空，则将它的左右子节点赋值，每赋值一次，pos都会加一，指向下一个可用来赋值的子节点
                    if (pos < num.size()) num[j]->left = num[pos++];
                    if (pos < num.size()) num[j]->right = num[pos++];
                }
            }
            last = end[i];  
        }
        return num[0];
    }
};
```