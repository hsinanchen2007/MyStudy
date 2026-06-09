### 解题思路
这题采用了graham算法。
具体介绍可以看[https://zhuanlan.zhihu.com/p/33355636](计算几何第一周：凸包（Convex Hull）)
并且结合LeetCode官方题解里的那个动图理解。

简单地说，分成以下几步。
1. 会利用叉积计算区分三个点之间的相对位置
2. 按照极角大小和距离远近排序
3. 建立一个栈，运行graham算法
4. 最后还有一步就是 由于这题要求把边上的点都加入集合中，
所以需要在最后，把与points[0]和points[n-1]共线的点都加入集合中，
因为排序后points[0]和points[n-1]必为极点，然后根据上面的排序，
如果不做这一步的话，就会漏掉一些点。
至于为什么只需要考虑那些与points[0]和points[n-1]共线的点，
这个问题可以好好思考，其实十分显然。

如果对于上面第四点依旧不理解，那下面给出一个样例，可以自行尝试：
[[3,0],[4,0],[5,0],[6,1],[7,2],[7,3],[7,4],[6,5],[5,5],[4,5],[3,5],[2,5],[1,4],[1,3],[1,2],[2,1],[4,2],[0,3]]
如果缺少了第四步，只是按部就班做了前三步的话，就会漏掉[1,4]这个点。

### 代码

```cpp
class Solution {

int cross_mul(vector<int>& a,vector<int>& b, vector<int>& c) {//叉积
	int x1 = b[0] - a[0], y1 = b[1] - a[1];
	int x2 = c[0] - b[0], y2 = c[1] - b[1];

	return x1 * y2 - x2 * y1;
}

int dis(vector<int>& a,vector<int>& b) {//计算两点距离
	int x = b[0] - a[0], y = b[1] - a[1];

	return x * x + y * y;
}

bool cmp(vector<int>& c,vector<int>& a,vector<int>& b) {//比较函数
	if (cross_mul(c, a, b) > 0)//实际上这里的c应该是排序后的points[0]，即左下角的极点
		return true;
	if (cross_mul(c, a, b) < 0)
		return false;
	return (dis(c, a) < dis(c, b));//共线的时候比较远近距离
}

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if(points.size()<=3)//显然了，点数小于等于三，直接输出就好
            return points;
        
      	int  n=points.size();
        
        int idx = 0;
		for (int i = 1; i < n; i++)
			if (points[i][0] < points[idx][0] || (points[i][0] == points[idx][0] && points[i][1] < points[idx][1]))//左下角的那个，必定就是极点
				idx = i;
		swap(points[0], points[idx]);

    	for(int i=1;i<n;i++)//最简陋的选择排序，可以换成快排，将时间复杂度降至n log n
    	for(int j=i+1;j<n;j++)
    	if(!cmp(points[0],points[i],points[j]))
    		swap(points[i],points[j]);

		vector<vector<int>> Ans;
		int top = 2;
		for (int i = 0; i < 3; i++)//第一第二个点必为极点，这里不妨先将前三个点入栈
			Ans.push_back(points[i]);

		for (int i = 3; i < n; i++) {//graham算法
			while (cross_mul(Ans[top - 1], Ans[top], points[i]) < 0) {
				Ans.pop_back();
				top--;
			}
			top++;
			Ans.push_back(points[i]);
		}
		top = n - 1;//下面执行第四步操作，我采用了取巧的写法，本质和我上面的讲解一致
		while(cross_mul(points[0],points[top - 1], points[top])==0){
			Ans.push_back(points[top-1]);
			top--;
		}

		return Ans;
    }
};
```