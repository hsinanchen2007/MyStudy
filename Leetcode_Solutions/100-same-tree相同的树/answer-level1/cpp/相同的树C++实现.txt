第一种实现：简单递归
缺点：容易爆栈（整个函数不是在第一次遭遇不同值的节点停止，而是要返回到root节点。）
```C++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) {
            return true;
        }

        if(p==NULL || q==NULL){
            return false;
        }

        if(p->val != q->val) {
            return false;
        }

        if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }

        return false;
    }
};
```

第二种实现：双stack做DFS，while循环替代函数栈，降低爆栈风险
（第一次遭遇不同取值的节点就终止整个函数）
```C++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;

        stk1.push(p);
        stk2.push(q);

        while(!stk1.empty() && !stk2.empty()) {
            p = stk1.top(); stk1.pop();
            q = stk2.top(); stk2.pop();

            // root
            if(p==NULL && q==NULL) {
                continue;
            }
            if(p==NULL || q==NULL) {
                return false;
            }
            if(p->val != q->val) {
                return false;
            }

            // children        
            // left
            stk1.push(p->left);
            stk2.push(q->left);

            // right
            stk1.push(p->right);
            stk2.push(q->right);
        }

        if(!stk1.empty() || !stk2.empty()) {
            return false;
        }

        return true;
    }
};
```

第三种实现：双端队列替代两个栈，纯粹的STL语法糖
```C++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<TreeNode*> dq;
        dq.push_front(p);
        dq.push_back(q);

        while(!dq.empty()) {
            p = dq.front(); dq.pop_front();
            q = dq.back();  dq.pop_back();

            // root
            if(p==NULL && q==NULL) {
                continue;
            }
            if(p==NULL || q==NULL) {
                return false;
            }
            if(p->val != q->val) {
                return false;
            }

            // children        
            // left
            dq.push_front(p->left);
            dq.push_back(q->left);

            // right
            dq.push_front(p->right);
            dq.push_back(q->right);
        }

        return true;
    }
};
```