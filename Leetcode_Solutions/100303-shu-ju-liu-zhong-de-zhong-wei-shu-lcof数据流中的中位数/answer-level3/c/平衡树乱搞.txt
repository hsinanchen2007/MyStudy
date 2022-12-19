### 解题思路
平衡树乱搞

二叉查找树查找第K大树的单次操作时间复杂度是O(树高)，使用平衡树可以保证单次O(logn)。在节点的value里加一个时间戳以保证每个节点的值都不同。

（正解是大小堆？果然上AVL还是有些大材小用了……）

### 代码

```cpp
struct AVLNode{
    int value, id, height, size;
    AVLNode *left, *right, *parent;
    bool operator < (const AVLNode &b){
        if(this->value != b.value)return this->value < b.value;
        else return this->id < b.id;
    }
    AVLNode(){
        value = id = height = size = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    int left_height(){
        return left==NULL ? 0 : left->height;
    }
    int right_height(){
        return right==NULL ? 0 : right->height;
    }
    int left_size(){
        return left==NULL ? 0 : left->size;
    }
    int right_size(){
        return right==NULL ? 0 : right->size;
    }
    void turn_left(){
        AVLNode *p = this;
        AVLNode* p_right = p->right;
        //cout << "P = " << p->value << "PR = " << p_right->value << "PPR = " << p->parent->value << endl;
        p->right = p_right->left;
        if(p_right->left!=NULL)p_right->left->parent = p;
        p_right->left = p;
        if(p->parent->left == p) p->parent->left = p_right;
        else p->parent->right = p_right;
        p_right->parent = p->parent;
        p->parent = p_right;
        p->refresh_height();
        p->refresh_size();
        p_right->refresh_height();
        p_right->refresh_size();
    }
    void turn_right(){
        AVLNode *p = this;
        AVLNode* p_left = p->left;
        //cout << "P = " << p->value << "PL = " << p_left->value << "PPR = " << p->parent->value << endl;
        p->left = p_left->right;
        if(p_left->right!=NULL)p_left->right->parent = p;
        p_left->right = p;
        if(p->parent->left == p) p->parent->left = p_left;
        else p->parent->right = p_left;
        p_left->parent = p->parent;
        p->parent = p_left;
        p->refresh_height();
        p->refresh_size();
        p_left->refresh_height();
        p_left->refresh_size();
    }
    void turn_left_turn_right(){
        AVLNode *p = this;
        p->left->turn_left();
        p->turn_right();
    }
    void turn_right_turn_left(){
        AVLNode *p = this;
        //cout << "TRTL " << p->value << endl;
        p->right->turn_right();
        p->turn_left();
    }
    void refresh_height(){
        AVLNode *p = this;
        int h_left = p->left==NULL ? 0 : p->left->height;
        int h_right = p->right==NULL ? 0 : p->right->height;
        p->height = max(h_left, h_right) + 1;
    }
    void refresh_size(){
        int s_left = this->left==NULL ? 0 : this->left->size;
        int s_right = this->right==NULL ? 0 : this->right->size;
        this->size = s_left + s_right + 1;
    }

    void balance(){
        if(this->left_height() >= this->right_height()+2){
            if(this->left->left_height()>this->left->right_height()){
                this->turn_right();
            }
            else{
                this->turn_left_turn_right();
            }
        }
        else if (this->right_height() >= this->left_height()+2){
            if(this->right->left_height()>this->right->right_height()){
                this->turn_right_turn_left();
            }
            else{
                this->turn_left();
            }
        }
    }
};

struct AVLTree{
    AVLNode *root, *grandroot;
    int tree_size;

    AVLTree(){
        root = NULL;
        grandroot = new AVLNode();
        grandroot->left = root;
        tree_size = 0;
    }

    ~AVLTree(){
        queue<AVLNode*> Q;
        while(!Q.empty())Q.pop();
        Q.push(root);
        while(!Q.empty()){
            AVLNode* top = Q.front();
            Q.pop();
            if(top == NULL)continue;
            if(top->left != NULL)Q.push(top->left);
            if(top->right != NULL)Q.push(top->right);
            delete top;
        }
        delete grandroot;
    }

    void insert(int key){
        tree_size ++;
        if(root == NULL){
            root = new AVLNode();
            root->value = key;
            root->parent = grandroot;
            root->id = tree_size;
            root->refresh_size();
            root->refresh_height();
            grandroot->left = root;
        }
        else{
            AVLNode *p = root;
            AVLNode *q = new AVLNode();
            q->value = key;
            q->size = 1;
            q->height = 1;
            q->id = tree_size;
            while(1){
                if(*p<*q){
                    if(p->right != NULL)p=p->right;
                    else{
                        p->right = q;
                        q->parent = p;
                        p->refresh_height();
                        p->refresh_size();
                        break;
                    }
                }
                else{
                    if(p->left != NULL)p=p->left;
                    else{
                        p->left = q;
                        q->parent = p;
                        p->refresh_height();
                        p->refresh_size();
                        break;
                    }
                }
            }
            while(p != grandroot){
                p->refresh_height();
                p->refresh_size();
                p = p->parent;
            }
            p = q;
            while(q != grandroot && abs(q->left_height()-q->right_height())<2){
                //cout << 'Q' << q->value << ' ' << q->id << endl;
                q = q->parent;
            }
            if(q != grandroot){
                q->balance();
                root = grandroot->left;
            }
            while(p != grandroot){
                p->refresh_height();
                p->refresh_size();
                p = p->parent;
            }
        }
    }

    int Kth(int k){
        AVLNode *p = root;
        //cout << "root = " << root->value << endl;
        while(k > 0){
            //cout << p->value << "left is " << (p->left==NULL?-999:p->left->value) << " right is " << (p->right==NULL?-999:p->right->value) << endl;
            if(p->left_size()<k){
                if(p->left_size() == k-1){
                    break;
                }
                k -= (p->left_size()+1);
                p = p->right;
            }
            else{
                p = p->left;
            }
        }
        return p->value;
    }
};

class MedianFinder {
    AVLTree *tree;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        tree = new AVLTree;
    }
    
    void addNum(int num) {
        //cout << "add " << num << endl;
        this->tree->insert(num);
    }
    
    double findMedian() {
        //cout << "FM" << endl;
        int size = this->tree->tree_size;
        if(size&1){
            return double(this->tree->Kth(size/2+1));
        }
        else{
            double med_left = this->tree->Kth(size/2);
            double med_right = this->tree->Kth(size/2+1);
            return (med_left+med_right)/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```