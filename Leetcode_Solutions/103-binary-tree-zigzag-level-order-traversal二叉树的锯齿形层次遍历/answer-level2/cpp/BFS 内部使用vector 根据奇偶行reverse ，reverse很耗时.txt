### 知识点记录
知识点：二维vector的使用方式
**参考了其他大佬的解析**

思路1.  使用dequeue，根据level的奇偶性，dequeue.push_back()/ dequeue.push_front() 
最后将dequeue填充res.            
res.push_back(vector<int>(temp.begin(), temp.end()));  //添加到结果中

思路2： 由于STL vector有reverse方法，可以就使用vector存储，在特定的偶数行对vector 做reverse操作
	
但通过提交对比发现  solution1  VS  solution2   耗时 0ms  VS 4ms，表明vector做reverse很耗时

### 代码

vector --reverse 4ms
```cpp
class Solution2 {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

		vector<vector<int>> res;

		if(root==nullptr) return res;
		
		queue<TreeNode*> que;
		que.push(root);

		int depth = 0;
		while(!que.empty()) {
			int levSize = que.size();
			vector<int> vec;
			while(levSize--) {
				auto tmp = que.front(); que.pop();
				vec.push_back(tmp->val);

				if(tmp->left) que.push(tmp->left);
				if(tmp->right) que.push(tmp->right);
			}

			// 判断改行是奇偶及是否进行翻转
			if(depth%2) reverse(vec.begin(), vec.end());

			// 对应该行的vec已经存储完毕了,翻转一下就好了
			res.push_back(vec);
			depth++;			
		}
	return res;
	}
	
};

```

dequeue 0ms
```cpp
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            deque<int> temp;  //双端队列
            while(n--) {
            // for(int i = 0; i < n; i++){  // 一层
                TreeNode* p = q.front();
                q.pop();
                if(level % 2 == 0)
                    temp.push_back(p->val);  //偶数层在后面加（从零层开始算），即从左往右
                else
                    temp.push_front(p->val);  //奇数层在前面加（从零层开始算），即从右往左
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.push_back(vector<int>(temp.begin(), temp.end()));  //添加到结果中
            level++;
        }
        return res;
    }
};
```
