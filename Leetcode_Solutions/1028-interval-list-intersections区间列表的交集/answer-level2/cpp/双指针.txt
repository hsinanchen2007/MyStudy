### 解题思路
不断向前移动指针，把所有不可能情形排除，复杂度O(N).

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<int>interval = { 0,0 };
	vector<vector<int>>res;
	int A_size = A.size();
	int B_size = B.size();
    if(A.size()==0||B.size()==0)
       return res;
	bool**access = new bool*[A_size];
	for (int i = 0; i < A_size; i++)
	{
		access[i] = new bool[B_size];
		for (int j = 0; j < B_size; j++)access[i][j] = false;
	}
	int a = 0;
	int b = 0;
	for (int i = 0; i < A_size; i++)
	{
		while (B[a][1] < A[i][0])
		{
			if (a < B_size - 1)
				a++;
			else break;
		}
		int aa = A[i][0] < B[a][0] ? B[a][0] : A[i][0];
		int bb = A[i][1] > B[a][1] ? B[a][1] : A[i][1];
		if (aa <= bb)
		{
			interval[0] = aa;
			interval[1] = bb;
			if (!access[i][a])
				res.push_back(interval);
			access[i][a] = true;
		}
		while (B[b][0] <= A[i][1])
		{
			int aa = A[i][0] < B[b][0] ? B[b][0] : A[i][0];
			int bb = A[i][1] > B[b][1] ? B[b][1] : A[i][1];
			if (aa <= bb)
			{
				interval[0] = aa;
				interval[1] = bb;
				if (!access[i][b])
					res.push_back(interval);
				access[i][b] = true;
			}
			if (b < B_size - 1)
				b++;
			else break;
		}
	}
    return res;
    }
};
```