```
#include <vector>
#include <string>
#include <deque>

using namespace std;

struct MyNode {
	TreeNode *tn;
	int lvl;

	MyNode(TreeNode *p, int level) : tn(p), lvl(level) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
    	deque<MyNode> dq;
    	doSearch(dq, S, 0);

    	return mTreeNode;
    }

    void doSearch(deque<MyNode> &dq, string &S, size_t loc) {
    	if (loc >= S.size()) {
    		return;
    	}

    	// 先找-，得到level
    	size_t tmpLoc = loc;
    	int level = 0;
    	while (tmpLoc < S.size() && S[tmpLoc] == '-') {
    		level += 1;
    		tmpLoc += 1;
    	}

    	// 再找数字
    	string num;
    	while (tmpLoc < S.size() && isdigit(S[tmpLoc])) {
    		num += S[tmpLoc];
    		tmpLoc += 1;
    	}

    	TreeNode *p = new TreeNode(atoi(num.c_str()));
    	MyNode mn(p, level);

    	if (level == 0) {
    		mTreeNode = p;
    		dq.push_back(mn);
    	}
    	else {
    		// 退栈找父节点
    		while (!dq.empty() && dq.back().lvl != level - 1) {
    			dq.pop_back();
    		}

    		// 优先挂左节点
        	if (dq.back().tn->left == NULL) {
        		dq.back().tn->left = p;
        	}
        	else {
        		dq.back().tn->right = p;
        	}

        	// 当前节点入栈
        	dq.push_back(mn);
    	}

    	doSearch(dq, S, tmpLoc);
    }

private:
    TreeNode *mTreeNode; // root节点
};
```
