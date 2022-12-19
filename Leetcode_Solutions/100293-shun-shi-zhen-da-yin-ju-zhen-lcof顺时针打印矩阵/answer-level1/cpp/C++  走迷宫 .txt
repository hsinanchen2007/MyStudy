常规思路，向右走，走不通再向下走，走不通再向左，走不通再向上。走过的地方不能再走，直到走过了m*n个元素。
```
class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
	int m=matrix.size();
    if(m==0)return ans;
    int n=matrix[0].size();
	int d[m][n];
    memset(d,0,sizeof(d));
	int x=0,y=0,all=m*n,c=1;
    d[0][0]=1;
	ans.push_back(matrix[x][y]);
	while(c<all){
        if(c>=all)break;
		while(y+1<n){
			if(d[x][y+1]!=0)break;
				y++;
                // cout<<c<<" "<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
				ans.push_back(matrix[x][y]);
				d[x][y]=1;
				c++;
				if(c>=all)break;
		}
        if(c>=all)break;
		while(x+1<m){
			if(d[x+1][y]!=0)break;
				x++;
				ans.push_back(matrix[x][y]);
                //cout<<c<<" "<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
				d[x][y]=1;
				c++;
				if(c>=all)break;
		}
        if(c>=all)break;
		while(y-1>=0){
			if(d[x][y-1]!=0)break;
				y--;
				ans.push_back(matrix[x][y]);
               //cout<<c<<" "<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
				d[x][y]=1;
				c++;
				if(c==all)break;
		}
        if(c>=all)break;
		while(x-1>=0){
			if(d[x-1][y]!=0)break;
				x--;
				ans.push_back(matrix[x][y]);
               //cout<<c<<" "<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
				d[x][y]=1;
				c++;
				if(c>=all)break;
		}
	}
	
	return ans;
}
};
```


