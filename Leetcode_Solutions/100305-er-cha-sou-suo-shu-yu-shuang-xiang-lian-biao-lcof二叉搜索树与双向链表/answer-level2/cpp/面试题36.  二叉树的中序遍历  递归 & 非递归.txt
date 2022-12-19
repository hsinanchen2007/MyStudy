```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// 递归的中序遍历 
class Solution {

private:
    Node * head = NULL;
    Node * last = NULL;

    void inTravel(Node * root) {
        if (root == NULL)
            return;
        inTravel(root->left);
        //----- 这里将会遍历到的一串从小到大的值 -----
        if (last == NULL) {  //last == NULL 说明是最小的值
            last = root;
            head = root;
        }
        else {
            last->right = root;
            root->left = last;
            last = root;
        }
        //------------------------------------
        inTravel(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        
        if (root == NULL) 
            return root;
        inTravel(root);
        head->left = last;  //首尾相接
        last->right = head;
        return head;
               
    }
};


// // 2. 非递归的中序遍历 
// class Solution {
// public:
//     Node* treeToDoublyList(Node* root) {

//         if (root == NULL) return root;
        
//         Node * head = NULL;
//         Node * pre = NULL;
        
//         stack< pair< Node*, bool> > S;
//         S.push(make_pair(root, false));
//         bool visit;
//         while (!S.empty()) {
//             root = S.top().first;
//             visit = S.top().second;
//             S.pop();
//             if (root == NULL)
//                 continue;
//             if (visit) {
//                 if (pre == NULL) {  //中序遍历的第一个结点
//                     head = root;
//                     pre = root;
//                 }
//                 else {
//                     root->left = pre;
//                     pre->right = root;
//                     pre = root;
//                 }
//             }
//             else {
//                 S.push(make_pair(root->right, false));
//                 S.push(make_pair(root, true));
//                 S.push(make_pair(root->left, false));
//             }
//         }
//         head->left = pre;
//         pre->right = head;
//         return head;
        
//     }
// };














```