方法按照时间复杂度由大到小介绍
首先能想到的是用DSF暴力递归，显然这种方法必定超时，时间复杂度在n^k(?)
画出递归树，可以看出，递归计算了大量重复的式子，浪费了时间和空间，带"备忘录"的递归能否不超时？
```
int solve(int arr[], int n)
{
	if (n < 0) return -1;
	int cur = n, pre;
	for (int i = sqrt(n); i >= 1; i--)
	{
		pre = solve(arr, n - arr[i]) + 1;
		if (pre && cur > pre) cur = pre;
	}
	return cur;
}
```
然后就是BFS,对于BFS在最值问题的突破点就是叶结点，本题要求以最少的数凑到N,问题就转化为哪个分支最先到达叶结点
具体到本题就是记录每一层，直到出现叶结点（(temp == i * i）,返回level
```
        int level = 0;
        queue<int> q;
        q.push(n);
        vector<bool> visit(n + 1, false);
        while(!q.empty())
        {
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++)
            {
                int temp = q.front();
                q.pop();
                visit[temp] = true;
                for(int i = 1; i * i <= temp; i++)
                {
                    if(temp == i * i) return level;
                    if(!visit[temp - i * i]) q.push(temp - i * i);
                }
            }
        }
```
第三种是DP在最值型问题的应用
先确定状态：对于问题规模为n的最后一步，最少用(n - a) + 1次凑到n(转化为子问题);
设状态f（x）= 最少用多少次凑到x
a满足a = k^2 <= n
f(n) = min{f(n - a) + 1}
**写出了状态转移方程:f(n) =  min{f(n - a) + 1, a = k^2 <= n} **
时间复杂度为O(M*N),空间复杂度为O(N)
```
    int numSquares(int n) {
        int *p = new int[n + 1];
        p[0] = 0;
        for(int i = 1; i < n + 1; i++)
        {
            int min = 1000;
            for(int j = 1; j*j <= i; j++)
                if(p[i - j*j] + 1 < min) min = p[i - j*j] + 1;
            p[i] = min;
        }
        return p[n];
    }
```
最后一步是四平方和定理，套公式就行了 (逃