```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> v;
        int n = matrix.size();
        if(n<=0) return v;
		int m = matrix[0].size();
		int base = 0;  //层级 从外到内
		
		// 外层 
		while(m>1 && n>1){
			
			int t[4][2] = {{0,0},{0,m-1},{n-1,m-1},{n-1,0}}; //四个角落
        	int f[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //行走方向
        	int row,col=0;
        	
        	for(int i=0;i<4;i++)  
        	{
        		int border;
        		if(f[i][0]!=0) border = n;
        		else border = m;
        		for(int j=0;j<border-1;j++){
        			row = t[i][0] + j * f[i][0] + base;
        			col = t[i][1] + j * f[i][1] + base;
					v.push_back(matrix[row][col]);        			
				}
			}
			
			base++;
			n-=2;
			m-=2;
		}
		
		// 最后一层 
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		v.push_back(matrix[base+i][base+j]);
		
		return v;
    }
};
```
