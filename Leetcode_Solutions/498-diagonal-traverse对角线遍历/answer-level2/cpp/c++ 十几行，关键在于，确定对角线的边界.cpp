//执行用时 :24 ms, 在所有 C++ 提交中击败了98.82%的用户
//内存消耗 :18.9 MB, 在所有 C++ 提交中击败了5.24%的用户
```
//每个 对角线，下标和从0 到m-n-2。 
//下标和是偶数，往上走，下标和奇数，往下走 
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    	vector<int>	res;
		if(matrix.empty())	return res;
 		int m = matrix.size();
		int n = matrix[0].size();   //m,n行数和列数
		for(int count=0;count<=m+n-2;count++){
			if(count%2==0){		//偶数从下往上，用i表示行
				for(int i=min(count,m-1);i>=0&&(count-i)<n;i--)
					res.push_back(matrix[i][count-i]);
			}
			if(count%2!=0){		//奇数，从上往下，用j表示列
				for(int j=min(count,n-1);j>=0&&(count-j)<m;j--)
					res.push_back(matrix[count-j][j]);
			} 	
    	}
    	return res;
	}
};


```
