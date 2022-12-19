```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>res;
        vector<int>temp[n];
		int matrix[n][n]={0};//先建立一个矩阵 把值存入到矩阵当中去
		int u=0,l=0,k=1;
		int d=n-1,r=n-1;//边界条件值
		while(true){
		for(int i=l;i<=r;++i)//向左移动
				matrix[u][i]=k++;
		if(++u>d) break;//重置边界值
		for(int i=u;i<=d;++i)//向下移动
				matrix[i][r]=k++;
		if(--r<l) break;//重置边界值
		for(int i=r;i>=l;--i)//向左移动
				matrix[d][i]=k++;
		if(--d<u) break;//重置边界值
		for(int i=d;i>=u;--i)//向上移动
				matrix[i][l]=k++;
		if(++l>r) break;
		}
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[i].push_back(matrix[i][j]);//按行把矩阵中的值放入到容器中
                }
            for（int i=0;i<n;i++）
                    res.push_back(temp[i]);
            return  res;
        }
    };
```
