解法1：单调栈  
以第i行为底求直方图的最大正方形面积维护高度h  
直方图的最大正方形面积维护增单调栈来求    
复杂度O(n*m) ，运行36ms  
```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();if(n==0)return 0;
        int m=matrix[0].size();
        int ans=0;
        vector<int>h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    h[j]=matrix[i][j]-'0';
                }else{
                    h[j]=(matrix[i][j]=='1')?(h[j]+1):0;
                }
            }
            //for(int j=0;j<m;j++)printf("%d ",h[j]);puts("");
            ans=max(ans,largestRectangleArea(h));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();if(n==0)return 0;
        
        int *l=new int[n+2];//l[i]:ai为最小值的左端点-1
        int *r=new int[n+2];//r[i]:ai为最小值的右端点+1
        int *a=new int[n+2];a[0]=-1;a[n+1]=-1;
        for(int i=0;i<heights.size();i++)a[i+1]=heights[i],l[i+1]=r[i+1]=0;
        stack<int>s;//维护栈内元素单调增的栈
        for(int i=0;i<=n;i++){
            while(!s.empty()&&a[s.top()]>=a[i])s.pop();
            //while结束，此时栈顶比a[i]小，所以栈顶就是i为最小值的左端点-1
            
            if(s.empty())l[i]=i-1;//栈空时防止溢出
            else l[i]=s.top();
            s.push(i);
        }
        
        while(!s.empty())s.pop();
        
        for(int i=n+1;i>=1;i--){//反过来跑一遍就能维护出右端点r[i]
            while(!s.empty()&&a[s.top()]>=a[i])s.pop();
            if(s.empty())r[i]=i+1;
            else r[i]=s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,min(r[i]-l[i]-1,a[i])*min(r[i]-l[i]-1,a[i]));
            //cout<<i<<" l:"<<l[i]<<" r:"<<r[i]<<endl;
        }
        return ans;
    }
};
```
解法2：动态规划 复杂度O(nm)  ，运行12ms

```
class Solution {
public:
    int dp[2][5005];//dp[i][j]以(i,j)为右下角的最大正方形宽度，节省空间滚动一下
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();if(n==0)return 0;
        int m=matrix[0].size();
        int ans=0;
        
        for(int i=1,t=0;i<=n;i++,t^=1){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1]=='1')
                    dp[t][j]=min(dp[t^1][j-1],min(dp[t][j-1],dp[t^1][j]))+1;
                else dp[t][j]=0;
                ans=max(dp[t][j],ans);
            }
        }
        return ans*ans;
    }

};
```