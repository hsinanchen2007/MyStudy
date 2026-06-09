/** 96. 不同的二叉搜索树
 *  典型的动态规划题，重点在于找出转移方程：
 *  R(n) = ∑[R(i) * R(n-1-i)],i∈[0,n-1];
 **/
int numTrees(int n) {
	vector<int> res = { 1,1,2 };	//res[i]表示节点为i时，二叉搜索树的个数，
	res.resize(n + 1);				//i从0开始，即规定：0个节点时也是一种情况，所以总个数应该是n+1个
	for (int i = 3; i < n + 1; i++) //i表示节点个数
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += res[j] * res[i - 1 - j];  //见状态转移方程
		}
		res[i] = sum;
	}
	return res[n];
}