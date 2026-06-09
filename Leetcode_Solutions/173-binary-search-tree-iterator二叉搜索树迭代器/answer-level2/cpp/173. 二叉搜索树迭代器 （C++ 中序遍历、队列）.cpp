# 173. 二叉搜索树迭代器
**思路**
如图所示：

![图片.png](https://pic.leetcode-cn.com/ae80969a03919bd33c28e33d87980b77cf56e2fb71a2c5d18067bb3afdde1e5f-%E5%9B%BE%E7%89%87.png)

- 题目中给出一颗二叉搜索树，要求通过函数返回下一个最小节点，与下一个最小节点是否存在。
- 实际上就是要将这个二叉树的所有节点按照升序存储起来，每次调用next()时从升序序列中取出第一个元素，当这个升序序列为空时也就不存在下一个最小节点了。
- 由于题目给出的是二叉搜索树，所以：
    1. 每个二叉搜索树节点的左孩子节点val总小于该节点val；
    2. 每个二叉搜索树节点的右孩子节点val总大于该节点val；
- 所以如果我们先遍历左子树、再访问当前节点、再遍历右子树得到的序列就为一个升序序列，正好与中序遍历二叉树方式相同，那么我们就可以中序遍历这个二叉搜索树。
- 又有应为得到的是升序序列，而每次返回的是序列第一个元素，则可以利用队列先进先出的特性，存储中序遍历序列。

**完整代码：**
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
	queue<int> m_queue;	//保存数据队列
public:
	//中序遍历
	void inorderRevurtion (TreeNode* temp) {
		if(temp != NULL){
			inorderRevurtion(temp->left);
			m_queue.push(temp->val);
			inorderRevurtion(temp->right);
		}
	}
	
    BSTIterator(TreeNode* root) {
        
		inorderRevurtion(root);
    }
    
    /** @return the next smallest number */
    int next() {
		int next = m_queue.front();
		m_queue.pop();
		return next;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(m_queue.empty())
			return false;
		else
			return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

