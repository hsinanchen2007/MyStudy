
**我是用栈实现:** 

```cpp
using  namespace  std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    TreeNode  *__T;
    stack<TreeNode*> __st;
    BSTIterator(TreeNode* root) {
        if(root){//这判不判断都行
            push_node(root);
        }
    }
    //我总觉得,所有的题解好像都不能让 next 函数变为o(1),无论如何都要找到下一个节点的呀
    //除非在构造函数的时候,把所有节点放到一个数阻里,但是不优雅
    //所以也不想那样做,只有这样 摸鱼 这样子
    /** @return the next smallest number */
    int next(){
        int __res = __st.top()->val;
        TreeNode *__tmp = __st.top()->right;
        __st.pop();
        if(__tmp){//这判不判断都行
            push_node(__tmp);
        }
        return __res;
    }
    /** @return whether we have a next smallest number */
    bool hasNext(){
        return !__st.empty();
    }
    //自己写的辅助函数
    void push_node(TreeNode *__root){
        TreeNode *__tmp = __root;
        while(__tmp){
            __st.push(__tmp);
            __tmp = __tmp->left;
        }
    }
};
```