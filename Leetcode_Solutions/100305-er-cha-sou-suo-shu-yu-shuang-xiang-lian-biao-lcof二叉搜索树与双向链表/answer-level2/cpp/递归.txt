    class Solution {
    public:
        Node* treeToDoublyList(Node*& root) {
            if(!root)return NULL;
            Node* left_head = treeToDoublyList(root->left);
            Node* right_head = treeToDoublyList(root->right);
            if(!root->left && !root->right){
                root->left = root;
                root->right = root;
                return root;
            }
            else if(!root->left){
                root->right = right_head;
                root->left = right_head->left;
                right_head->left->right = root;
                right_head->left = root;
                return root;
            }
            else if(!root->right){
                root->right = left_head;
                root->left = left_head->left;
                left_head->left->right = root;
                left_head->left = root;
                return left_head;
            }
            else{
                root->left = left_head->left;
                left_head->left->right = root;
                left_head->left = right_head->left;
                root->right = right_head;
                right_head->left->right = left_head;
                right_head->left = root;
            }
            return left_head;
        }
    };