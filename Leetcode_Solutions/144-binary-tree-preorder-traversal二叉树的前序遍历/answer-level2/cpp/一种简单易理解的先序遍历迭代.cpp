我们同样借用栈的结构来实现迭代。先序遍历的递归形式，不难看出为尾递归。尾递归变为迭代将会容易许多。
**递归**:
```cpp
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return res;
        res.push_back(root->val);


        //以下为递归调用，任何一次递归调用执行具有实质效果的代码都是上面的代码，这就如同迭代
        //任何一次迭代都将执行相同形式的代码，尾递归形式是最好转为迭代的。
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};
```

**迭代1**:
>遗憾的是，该迭代形式尽管十分容易理解但却并不通用与中序，后序。
```cpp
class Solution {
public: 
    vector<int> res;

    vector<int> preorderTraversal(TreeNode* root) {
        stack<const TreeNode*> S; //维护一个临时的辅助栈,元素为指向节点的指针,由于我们不修改节点数据设定底层const

        if (root) S.push(root); //根节点存在，入栈

        while (!S.empty())  //栈非空，往返循环
        {
            //以下代码的作用为:访问局部root节点，在依次访问左孩子，右孩子节点，此为先序遍历
            //若孩子节点不存在，即为空，没有任何实质操作，我们用if限制这种特殊情况
            auto t = S.top();
            vist(t, res);
            S.pop();

            if (t->right)   S.push(t->right);
            if (t->left)    S.push(t->left);
        }
        return res;
    }
    //对节点进行访问，依据题目不同要求可做修改，该题目要求为读取数据
    inline void vist(const TreeNode* node, vector<int>& res)
    {
        res.push_back(node->val);
    }
};
```

**迭代2：**
>该算法的思想不难懂，但是比较难用文字表达。
```cpp
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        /
        stack<TreeNode*> s;

        while (true)
        {
            vistAlongLeft(s, root);
            
            if (s.empty()) return res;

            root = s.top();
            s.pop();
        }
    }

    void vistAlongLeft(stack<TreeNode*>& s, TreeNode* t)
    {
        while (t)
        {
            res.push_back(t->val);
            s.push(t->right);
            t = t->left;
        }
    }
};
```