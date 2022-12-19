### 解题思路
核心要点:序列化时使用deque按层遍历二叉树，注意ostringstream的使用格式，队头为null时只输出到结果和弹出，不为null时还要把左右节点加入队尾；反序列化时先读入一遍，使用vector存放节点，再遍历vector一遍，使用i和j两个标记添加节点间的指针
执行用时 :56 ms, 在所有 C++ 提交中击败了32.74%的用户
内存消耗 :23.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        deque<TreeNode*>q(1,root);
        ostringstream os;
        while(!q.empty()){
            if(q.front()==NULL){
                os<<"null ";
                q.pop_front(); 
            }
            else{
                os<<q.front()->val<<' ';
                q.push_back(q.front()->left);
                q.push_back(q.front()->right);
                q.pop_front();
            }
        }
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        vector<TreeNode*>list;
        string val;
        while(is>>val){
            if(val=="null"){
                list.push_back(NULL);
            }
            else{
                list.push_back(new TreeNode(stoi(val)));
            }
        }
        for(int i=0,j=1;j<list.size();i++){
            if(list[i]==NULL)continue;
            if(j<list.size())list[i]->left=list[j++];
            if(j<list.size())list[i]->right=list[j++];
        }
        return list[0];     
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```