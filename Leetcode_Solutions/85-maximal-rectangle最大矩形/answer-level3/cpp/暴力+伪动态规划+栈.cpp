介绍三种比较容易理解方法
分别是基础的暴力法，利用动态规划思想，但结合了暴力的方法，还有就是利用上一题84题的解法
[个人github，求星星](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution)

## 方法一：暴力法
执行用时48ms 内存消耗10.5MB
1. 遍历matrix的所有节点，把matrix.at(i).at(j)想象成一个矩形的右下角那个点，  
2. 对matrix.at(i).at(j)所在节点向左遍历，找到连续都为1的长度minimum_long，求面积1*minimum_long
3. 然后i-1,重复第二点向左遍历，用两行较短的一边为minimum_long，面积2*minimum_long
4. 一直更新面积area，直到往上不是‘1’的时候就结束这个节点
5. 对下一个节点重复

## 方法二：伪动态规划
执行用时48ms 内存消耗10.9MB
1. 创一个vector<vector<int>> dp(row,vector<int>(column,0))
2. 首先搞定第一行和第一列
3. 对于剩下的来说开始遍历
4. 如果matrix.at(i).at(j)=='0' 那么dp.at(i).at(j)=max(dp.at(i-1).at(j),dp.at(i).at(j-1))
5. 如果matrix.at(i).at(j)=='1' 那么dp.at(i).at(j)=max(dp.at(i-1).at(j),dp.at(i).at(j-1),按照方法1的暴力法找包括当前节点的最大面积)

## 方法三：栈
执行用时36ms 内存消耗11.3MB
1. 首先要把上一题84题的动态栈给看会了（能做出来上一题的其他方法也行，但没那么快）
2. 我们把matrix一行一行来看，创vector<int> heights(column,0)
3. 如果matrix.at(i).at(j)=‘0’那么height.at(j)=0
4. 如果matrix.at(i).at(j)=‘0’那么height.at(j)=height.at(j)+1
5. 可以这样理解，如果当前行的对应j这个点即matrix.at(i).at(j)为0，那么它就连接不上上面一行，那么在这一行求最大矩形就暂时不会有这一列的意义了
6. 如果如果当前行的对应j这个点即matrix.at(i).at(j)为1，那么表明他能连接上一行对应的这一列
7. 明白好之后，对每一行都调用84题的函数去求当前行最大面积
8. 到下一行重复即可

```
方法1
class Solution {
public:
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int row=matrix.size();
	if (row<1)
		return 0;
	int column=matrix.at(0).size(),answer=0,minimum_long;
	for (int i=0;i<row;++i)
		for (int j=0;j<column;++j)
			if (matrix.at(i).at(j)=='1')
			{
				minimum_long=INT_MAX;
				int temporary_i=i,temporary_j=j;
				while (temporary_i>-1 && temporary_j>-1 && matrix.at(temporary_i).at(temporary_j)=='1')
				{
					int k=temporary_j,temporary_long=0;
					while (k>-1 && matrix.at(temporary_i).at(k)=='1')
					{
						++temporary_long;
						--k;
					}
					if (temporary_long<minimum_long)
						minimum_long=temporary_long;
					--temporary_i;
					int temporary_area=(i-temporary_i)*minimum_long;
					if (answer<temporary_area)
						answer=(i-temporary_i)*minimum_long;
				}
			}
    return answer;
}
};
```

```
方法2
class Solution {
public:
int find_its_Rectangle_include_itself(vector<vector<char>>& matrix,const int& i,const int &j)
{
	int minimum_long=INT_MAX,answer=0;
	int temporary_i=i,temporary_j=j;
	while (temporary_i>-1 && temporary_j>-1 && matrix.at(temporary_i).at(temporary_j)=='1')
	{
		int k=temporary_j,temporary_long=0;
		while (k>-1 && matrix.at(temporary_i).at(k)=='1')
		{
			++temporary_long;
			--k;
		}
		if (temporary_long<minimum_long)
			minimum_long=temporary_long;
		--temporary_i;
		int temporary_area=(i-temporary_i)*minimum_long;
		if (answer<temporary_area)
			answer=(i-temporary_i)*minimum_long;
	}
	return answer;
}
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int row=matrix.size();
	if (row<1)
		return 0;
	int column=matrix.at(0).size();
	vector<vector<int>> dp(row,vector<int>(column,0));
	if (matrix.at(0).at(0)=='1')
		dp.at(0).at(0)=1;
	else
		dp.at(0).at(0)=0;
	int temporary_long=dp.at(0).at(0);
	for (int i=1;i<column;++i)
		if (matrix.at(0).at(i)=='1')
		{
			++temporary_long;
			if (matrix.at(0).at(i-1)=='1')
				dp.at(0).at(i)=max(temporary_long,dp.at(0).at(i-1));
			else
				dp.at(0).at(i)=max(1,dp.at(0).at(i-1));
		}	
		else
		{
			temporary_long=0;
			dp.at(0).at(i)=dp.at(0).at(i-1);
		}	
	temporary_long=dp.at(0).at(0);
	for (int i=1;i<row;++i)
		if (matrix.at(i).at(0)=='1')
		{
			++temporary_long;
			if (matrix.at(i-1).at(0)=='1')
				dp.at(i).at(0)=max(temporary_long,dp.at(i-1).at(0));
			else
				dp.at(i).at(0)=max(1,dp.at(i-1).at(0));
		}	
		else
		{
			temporary_long=0;
			dp.at(i).at(0)=dp.at(i-1).at(0);
		}
	for (int i=1;i<row;++i)
		for (int j=1;j<column;++j)
			if (matrix.at(i).at(j)=='0')
				dp.at(i).at(j)=max(dp.at(i-1).at(j),dp.at(i).at(j-1));
			else
				dp.at(i).at(j)=max(dp.at(i-1).at(j),max(dp.at(i).at(j-1),find_its_Rectangle_include_itself(matrix,i,j)));
	return dp.at(row-1).at(column-1);
}
};
```

```
方法3
class Solution {
public:
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int row=matrix.size();
	if (row<1)
		return 0;
	int column=matrix.at(0).size(),answer=0,temporary;
	vector<int> heights(column,0);
	for (int i=0;i<row;++i)
	{
		for (int j=0;j<column;++j)
			if (matrix.at(i).at(j)=='0')
				heights.at(j)=0;
			else
				heights.at(j)=heights.at(j)+1;
		temporary=largestRectangleArea(heights);
		if (temporary>answer)
			answer=temporary;
	}
	return answer;
}
int largestRectangleArea(vector<int>& heights)
{
    int heights_size=heights.size();
	stack<int> stack_heights;
	stack_heights.push(-1);
    stack_heights.push(0);
	int temporary,temporary_top,answer=0;
	for (int i=1;i<heights_size;++i)
		if (heights.at(i)>heights.at(i-1))
			stack_heights.push(i);
		else
		{
			while(stack_heights.top()!=-1 && heights.at(i)<=heights.at(stack_heights.top()))
			{
				temporary_top=stack_heights.top();
				stack_heights.pop();
				temporary=heights.at(temporary_top)*(i-stack_heights.top()-1);
				if (temporary>answer)
					answer=temporary;
			}
			stack_heights.push(i);
		}	
	int after_loop_top=stack_heights.top();
	while (stack_heights.top()!=-1)
	{
		temporary_top=stack_heights.top();
		stack_heights.pop();
		temporary=heights.at(temporary_top)*(after_loop_top-stack_heights.top());
		if (temporary>answer)
			answer=temporary;
	}
    return answer;
}
};
```




