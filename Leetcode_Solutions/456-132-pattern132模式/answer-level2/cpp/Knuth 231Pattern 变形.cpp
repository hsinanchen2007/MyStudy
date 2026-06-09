参考[https://leetcode.com/problems/132-pattern/discuss/166953/Easy-and-concise-C%2B%2B-solution-using-a-stack-with-explanation-VERY-EASY-to-understand]()然后去查了下Wiki,总结如下
- 若一个序列可以通过栈作为辅助空间进行排序,则称为这个序列是**栈-可排序** 
- Knuth证明了一个序列是**栈-可排序**,当且仅当这个序列没有**231**模式,即不存在$i<j<k$使得$s_j<s_k<s_i$.
因此,一个navie的代码如下
```cpp
bool find132pattern(vector<int>& nums) {
	int n = nums.size();
	//栈,用来存放降序排列元素
	stack<int> st;
	//辅助数组,用来存放排序后的数组
	vector<int> ans;
	//从左到右寻找132模式
	//等价于从右到左寻找231模式
	//从而可以利用Knuth的方法来判断
	for (int i = n - 1; i >= 0; i--) {
		//利用栈,从栈底到栈顶的元素降序排列,例如 [3,2,1 
		//这样栈在碰到大于栈顶元素时,会按顺序pop到辅助数组中
		while (!st.empty() && st.top() < nums[i])
		{
			ans.push_back(st.top());
			st.pop();
		}
		st.push(nums[i]);
	}
	//栈中剩余的数pop到辅助数组
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	for (int i = 0; i < n - 1; i++) {
		//若存在逆序对,说明序列不是有序的
		if (ans[i] > ans[i + 1])
			return false;
	}
	return true;
}
```
整个过程包含三个数据结构
- 未处理的数组
- 栈
- 辅助数组,包含了从栈中pop的数据

定义`mid`,并且在每次从栈中将元素pop到辅助数组时更新`mid`.
进一步观察栈和辅助数组的性质,我们可以总结如下
- 性质1:未处理的数组,在最终的辅助数组中会位于mid之后
- 性质2:若栈非空,则栈底元素一定大于`mid`
那么综合性质1和性质2,若当前数小于mid,我们已经找到了231模式.
代码如下
```cpp
bool find132pattern(vector<int>& nums) {
	int n = nums.size();
	stack<int> st;
	int mid = INT_MIN;
	for (int i = n - 1; i >= 0; i--) {
		if (nums[i] < mid)
			return true;
		while (!st.empty()&&st.top()<nums[i])
		{
			mid = st.top();
			st.pop();
		}
		st.push(nums[i]);
	}
	return false;
}
```