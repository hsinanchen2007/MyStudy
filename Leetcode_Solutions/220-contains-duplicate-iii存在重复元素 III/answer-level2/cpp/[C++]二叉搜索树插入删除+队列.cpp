### 解题思路
实现一个二叉排序树(BST)并使用队列记录节点插入时间顺序，本题涉及二叉排序树的实现、查找、插入、删除，由于c++的特性删除时还需要记录被删除节点的父节点（不能把节点直接设为null)。大部分代码都用于实现二叉排序树的增删等操作，解题思路与官方题解相同。
### 代码

```cpp
class Solution{
    public:
        TreeNode* head = NULL;
        deque<int> q;
        TreeNode* pre = NULL;
        TreeNode* searchLeastLargest(TreeNode* root, int x){
            if(root == NULL) return NULL;
            if(root->val >= x){
                TreeNode* res = searchLeastLargest(root->left, x);
                if(res == NULL) return root;
                else return res;
            }else return searchLeastLargest(root->right, x); 
        }

        TreeNode* searchLargestLeast(TreeNode* root, int x){
            if(root == NULL) return NULL;
            if(root->val <= x){
                TreeNode* res = searchLargestLeast(root->right, x);
                if(res == NULL) return root;
                else return res;
            }else return searchLargestLeast(root->left, x);
        }

        TreeNode* add(TreeNode* root, int x){
            if(root == NULL){
                TreeNode* n = new TreeNode(x);
                q.push_back(n->val);
                return n;
            }
            if(root->val > x){
                if(root->left == NULL) root->left = add(root->left, x);
                else add(root->left, x);
            }
            else{
                if(root->right == NULL) root->right = add(root->right, x);
                else add(root->right,x );
            }
            return root;
        }

        TreeNode* find(TreeNode* root, int x){
            if(root == NULL) return NULL;
            if(root->val == x) return root;
            pre = root;
            if(root->val < x) return find(root->right, x);
            else return find(root->left, x);
        }
        void deleteNode(TreeNode* t){
            if(t->left || t->right){
                pre = t;
                TreeNode* cur;
                if(t->left) {
                    cur = t->left;
                    while(cur->right){
                        if(cur->right && cur->right->right == NULL) pre = cur;
                        cur = cur->right;
                    }
                }
                else{
                    cur = t->right;
                    while(cur->left){
                        if(cur->left && cur->left->left == NULL) pre = cur;
                        cur = cur->left;
                    }
                }
                int tmp = t->val;
                t->val = cur->val;
                cur->val = tmp;
                deleteNode(cur);
            }
            else{
                if(t == head) head = NULL;
                else (pre->left == t)? pre->left = NULL : pre->right = NULL;
                return;
            }
        }

        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            long lk = k, lt = t;
            for(int i=0;i<nums.size();i++){
                if(!head){
                    head = add(head, nums[i]);
                }
                else{
                    // Search for the least element that's > nums[i]
                    if(q.size() - 1 == lk) {
                        int tmp = q.front();
                        pre = NULL;
                        TreeNode* t = find(head, tmp);
                        q.pop_front();
                        deleteNode(t);
                    }
                    TreeNode* r  = searchLeastLargest(head, nums[i]);
                    TreeNode* l = searchLargestLeast(head, nums[i]);
                    if(r && (long)r->val - (long)nums[i] <= lt) return true;
                    if(l && long(nums[i]) - long(l->val) <= lt) return true;
                    add(head, nums[i]);
                }
            }
        return false;
    }
};

```