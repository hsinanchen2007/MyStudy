class Solution {
```
public:
       TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	    if (t1 == nullptr) return t2;
	    TreeNode * p1 = t1, *p2 = t2;
	    queue<TreeNode *> Q;
	    Q.push(p1);
	    Q.push(p2);
	    while (!Q.empty() || !Q.empty()){
		p1 = Q.front();
		Q.pop();
		p2 = Q.front();
		Q.pop();
            if (p1 == nullptr || p2 == nullptr){
		continue;
	    }
	    p1->val += p2->val;
            if (p1->left == nullptr){
		p1->left = p2->left;
	    }
            else {
		Q.push(p1->left);
		Q.push(p2->left);
	    }
            if (p1->right == nullptr){
		p1->right = p2->right;
	    }
            else {
		Q.push(p1->right);
		Q.push(p2->right);
	    }

        }
		return t1;
}
};