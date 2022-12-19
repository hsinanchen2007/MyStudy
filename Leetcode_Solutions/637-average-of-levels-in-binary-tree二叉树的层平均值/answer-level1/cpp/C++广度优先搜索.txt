对应于树的层次遍历，并分层处理每层的节点；
考虑用两个辅助队列，其一指向当前层节点，另一指向下一层节点 


```C++ []

#define tnp TreeNode* // 节点位置，宏定义，tnp:TreeNodePosition 

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> result;//即将返回的结果
		queue<tnp>* currentQ = new queue<tnp>;//辅助队列，存储当前层的树节点
		currentQ->push(root);//根节点入队
		queue<tnp>* nextQ = new queue<tnp>;//辅助队列，存储下一层的树节点
		do//逐层扫描
			bfs(currentQ, nextQ, result);//遍历每一层的值
		while (!currentQ->empty());//直到树没有下一层为止
		return result;//返回每层平均值
	}
private:
	void bfs(queue<tnp>*& currentQ, queue<tnp>*& nextQ, vector<double>& result) {
		double sum = 0;//记录当前层的树节点的值的和
		int count = 0;//记录当前层的树节点个数
		while (!currentQ->empty()){
			tnp x = currentQ->front();
			sum += x->val; count++;//加上当前树节点的值，并让计数器自增1
			if (x->left) nextQ->push(x->left);//下一层的节点入队（左孩子）
			if (x->right) nextQ->push(x->right);//下一层的节点入队（左孩子）
			currentQ->pop();
		}
		result.push_back(sum / count);//当前层的平均值加入向量
		//并将下一辅助队列和前辅助队列交换
		queue<tnp>* tempQ = currentQ;
		currentQ = nextQ;
		nextQ = tempQ;
	}

};


```

