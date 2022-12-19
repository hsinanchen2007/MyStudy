很简单的中序遍历题目，因为要转成排序的双向链表，很容易想到中序遍历是有序的数组，
因此在遍历是改变指针的方向即可。

```
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
       // 排序双向链表，因此使用中序遍历
       stack<Node*> st;
       Node* pre=nullptr, *head=root;
       while(root || !st.empty()) {
           if(root) {
               st.push(root);
               cout<<root->val<<endl;
               root = root->left;
           } else {
               root = st.top();
               st.pop();
               
               // 具体处理过程，其他的都是中序遍历的模板
               if(pre == nullptr) {
                   pre = root;
                   head = root;  // 此时是最小值
               } else {
                   // 更新节点
                   pre->right = root;
                   root->left = pre;
                   pre = root;
               }

               root = root->right;
           }
       }
       // 连接收尾元素
       pre->right = head;
       head->left = pre;
       return head; 
    }
};
```
[树算法相关题解](https://github.com/yqtaowhu/DataStructureAndAlgorithm/blob/master/programming/tree/tree.md)