```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        vector<int> first(size,0),second(size,0);
        if(size==0)return 0;
        if(size==1)return triangle[0][0];
        first[0]=triangle[0][0];
        for(int i=1;i<size;++i){
            for(int j=0;j<=i;++j){
                if(j==0){
                    second[j]=first[j]+triangle[i][j];
                }
                else if(j==i){
                    second[j]=first[j-1]+triangle[i][j];
                }
                else{
                    second[j]=min(first[j-1],first[j])+triangle[i][j];
                }
            }
            swap(second,first);
        }
        int ans=INT_MAX;
        for(auto a:first){
            ans=min(ans,a);
        }
        return ans;
    }
};
```
