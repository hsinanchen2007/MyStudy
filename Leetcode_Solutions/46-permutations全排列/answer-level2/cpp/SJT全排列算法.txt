采用SJT全排列算法，可以用迭代的方式输出全排列，效率较高，具体原理如下：

设[a1,a2 ... aN] 每一项都有向左或向右两个移动方向。
1) 初始化所有移动方向向左；
2) 如果移动方向的值比自己小，就可移动，比如 <1 >2 <3, 每个数字前箭头的方向表示该数字的移动方向，3可以移动，2和1不可移动；
3) 移动最大的可以动项，在上面例子中就是数字3；
4) 将所有比移动项大的项方向反转，重复第三步，直到不能移动为止。

这里我用了三个数组，pos、vec和dir
vec数组元素就是生成的全排列，数值从0到n-1
pos数组的第[i]项就是数值为i的元素在vec数组中的位置，用这个数组的目的是可以高效地从大到小寻找可移动的数字，已经修改数字的方向
dir数组存储数值为i的元素的移动方向，true为左，false为右
每次生成一个排列，根据vec数组中的元素，即可得到一个对应的nums数组的排列
```
class Solution {
public:
    vector<vector<int>> permute(const vector<int>& nums) {
	int n = nums.size();
	vector<int> pos(n), vec(n);
	for (int i = 0; i < n; ++i) {
		pos[i] = vec[i] = i;
	}

	vector<bool> dir(n, true);
	vector<vector<int>> rst = {nums};

	while (true) {

		int v = n - 1;
		int j = dir[v] ? pos[v] - 1 : pos[v] + 1;
		while (v > 0 && (j == n || j == -1 || vec[j] > v)) {
			--v;
			j = dir[v] ? pos[v] - 1 : pos[v] + 1;
		}

		if (!v) break;

		int i = pos[v];
		int u = vec[j];
		swap(vec[i], vec[j]);
		swap(pos[u], pos[v]);

		rst.push_back(vector<int>(n));
		for (int k = 0; k < n; ++k) {
			rst.back()[k] = nums[vec[k]];
		}

		while (v != n - 1) {
			++v;
			dir[v] = !dir[v];
		}
	}

	return rst;
    }
};
```
