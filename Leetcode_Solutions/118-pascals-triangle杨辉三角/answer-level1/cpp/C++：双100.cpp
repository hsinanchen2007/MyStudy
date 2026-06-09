### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	// 开辟杨辉三角的空间
        vector<vector<int>> data(numRows);
        
        // 如果输入为0，则直接输出。
        if (numRows == 0)
	    {
		    return data;
	    }
	    int i, j;

		// 将杨辉三角的顶端赋值为1
	    data[0].push_back(1);

		// 核心思想:找出杨辉三角的规律，发现每一行头尾都是1，中间第[j]个数等于上一行[j-1]+[j] 
	    for (i = 1; i < numRows; i++)
	    {
	    	// 继承上一行数据
		    data[i] = data[i - 1];
		    // 从后向前累加
    		for (j = i - 1; j > 0; j--)
	    	{
		    	data[i][j] += data[i][j - 1];
		    }
		    // 给末尾填上1
		    data[i].push_back(1);
	    }

	    return data;
    }
};
```