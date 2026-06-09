```
    int findLonelyPixel(vector<vector<char>>& picture) {
        // 如果某行或者某列有两个或者两个以上的B，则B不可能是孤独像素
        
        int m = picture.size(); if(m==0) return 0;
        int n = picture[0].size(); if(n==0) return 0;
        int ans = 0;
        for(int i=0; i<m; i++){
            int count =0;
            for(int j=0; j<n; j++){
                count += (picture[i][j]=='B');
            }
            if(count==1){
                // judge
                int pos = 0;
                while(picture[i][pos]!='B') pos++;
                int countB = 0;
                for(int k=0; k<m; k++){
                   countB += (picture[k][pos]=='B');
                }
                ans += (countB==1);
            }
        }
        return ans;
    }
```