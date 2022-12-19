1. **思路一**
暴力破解法
把一个矩阵分成一个一个正方形来讨论，每个位置都只需要转3次即可，然后演算出规律即可
执行用时 :4 ms, 在所有 C++ 提交中击败了97.29%的用户 
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户

2. **思路二**
先转置
然后根据中心列进行对称交换
这种方法比较好理解但速度略慢

**代码**

思路一
```
//思路一
@author: Zhenghao-Liu
class Solution {
public:
void rotate(vector<vector<int>>& matrix) 
{
    int matrix_size=matrix.size();
	if (matrix_size<=1)
		return;
	int box_rotate_times=matrix_size-1;
	for (int i=0;i<matrix_size/2;++i)
	{
		for (int j=i;j<box_rotate_times;++j)
		{
			swap(matrix.at(i).at(j),matrix.at(box_rotate_times-j+i).at(i));
			swap(matrix.at(box_rotate_times-j+i).at(i),matrix.at(box_rotate_times).at(box_rotate_times-j+i));
			swap(matrix.at(box_rotate_times).at(box_rotate_times-j+i),matrix.at(j).at(box_rotate_times));
		}
		--box_rotate_times;
	}	
}
};
```

思路二
```
//思路二
@author: Zhenghao-Liu
class Solution {
public:
void rotate(vector<vector<int>> &matrix)
{
	int matrix_size=matrix.size();
	if (matrix_size<=1)
		return;
	for (int i=0;i<matrix_size;++i)
		for (int j=i+1;j<matrix_size;++j)
			swap(matrix.at(i).at(j),matrix.at(j).at(i));
	for (int i=0;i<matrix_size/2;++i)
		for (int j=0;j<matrix_size;++j)
			swap(matrix.at(j).at(i),matrix.at(j).at(matrix_size-i-1));
}
};
```



