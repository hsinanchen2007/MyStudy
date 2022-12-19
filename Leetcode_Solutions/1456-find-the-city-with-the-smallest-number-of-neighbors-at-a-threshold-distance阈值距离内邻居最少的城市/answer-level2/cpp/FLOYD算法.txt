```
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
	for(int i=0;i<edges.size();i++){
		distance[edges[i][0]][edges[i][1]]=edges[2];
		distance[edges[i][1]][edges[i][0]]=edges[2];
	}
     
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j||distance[i][k]==INT_MAX||distance[k][j]==INT_MAX)continue;
				distance[i][j]=min(distance[i][k]+distance[k][j],distance[i][j]);
			}
		}
	}
	
	int ans=0,mincnt=INT_MAX,cnt=0;
	for(int i=0;i<n;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			if(i!=j&&distance[i][j]<=distanceThreshold)cnt++;
		}
		if(cnt<=mincnt){
			ans=i;
			mincnt=cnt;
		}
	}	 
	 return ans;
}
```
