每次从第i行第j列开始，尝试放入皇后，判断是否合法，只需要判断在第i行之前，第j列之前的行列；然后判断两个对角线，也是在第i行之前。不需要整行整列判断，只判断上述部分即可。
```
class Solution {
	bool isValid(vector<string> &v, int row, int col){
		bool valid=true;
		for(int i=0; valid && i<row; valid=v[i++][col]!='Q');
		for(int i=0; valid && i<col; valid=v[row][i++]!='Q');
		for(int i=row, j=col; valid && i-- && j--; valid=v[i][j]!='Q');
		for(int i=row, j=col; valid && i-- && ++j<v.size(); valid=v[i][j]!='Q');
		return valid;
	}
	void backtrack(vector<string> &v, int row, vector<vector<string> > &vs){
		if(row==v.size()){
			vs.push_back(v);
			return;
		}
		for(int col=0; col<v.size(); ++col){
			v[row][col]='Q';
			if(isValid(v,row,col)) backtrack(v,row+1,vs);
			v[row][col]='.';
		}
	}
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<string> v(n,string(n,'.'));
		vector<vector<string> > vs;
		backtrack(v,0,vs);
		return vs;
	}
};
```

![2019-06-20 10-14-17屏幕截图.png](https://pic.leetcode-cn.com/011ef29232285bb61b63f13f2e9cec1d3dfdbe83c3d31aeb34b55ec83a896b95-2019-06-20%2010-14-17%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)