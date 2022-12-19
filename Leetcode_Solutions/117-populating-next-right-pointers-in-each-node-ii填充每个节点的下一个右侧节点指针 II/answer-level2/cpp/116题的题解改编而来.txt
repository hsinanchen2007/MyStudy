```
class Solution {
    private:
        vector<Node*>temp;
public:
        void fun(vector<Node*>& temp){
            int m=temp.size();
            if(m==0)//终止条件
                return ;
                for(int i=0;i<m;i++){//遍历每一层
                        if(temp[i]->left){
                            temp.push_back(temp[i]->left);
                        }
                        if(temp[i]->right)
                          temp.push_back(temp[i]->right);
                        if(i+1<=m-1)//设置条件  每一层的最后一个节点不用处理
                            temp[i]->next=temp[i+1];
                }
                temp.erase(temp.begin(),temp.begin()+m);//再把当前层给清理干净
                fun(temp);//开始递归
        }
    Node* connect(Node* root) {
        if(root==nullptr)
            return nullptr;
            temp.push_back(root);
        fun(temp);
        return root;
    }
};

```
