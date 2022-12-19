//遍历到一点先把这个上边的所有表面积求出再看这个位置的上边和左边是否有，有了处理减去一部分  遍历下来就可以了
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum=0,t,t1;
        int row = grid.size(),col = grid[0].size();
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if(grid[i][j]!=0){
        			t = grid[i][j];
					sum+=(t*6-(t-1)*2);
					if(i>0){
						t1= grid[i-1][j];
						if(t1!=0){
							sum=sum-2*(t<t1?t:t1);
						}
					}
					if(j>0){
						t1= grid[i][j-1];
						if(t1!=0){
							sum=sum-2*(t<t1?t:t1);
						}	
					}
				}
			}
		}
		return sum;
    }
};
```

