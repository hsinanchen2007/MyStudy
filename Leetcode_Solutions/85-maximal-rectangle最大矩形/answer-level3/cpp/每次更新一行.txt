```
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row_size=matrix.size();
        if(row_size==0){
            return 0;
        }
        int col_size=matrix[0].size();
        vector<int> v(col_size,0);
        int ans=INT_MIN;
        for(int i=0;i<row_size;++i){
            for(int j=0;j<col_size;++j){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]+=1;
                }
            }
            upDate(v,ans);
        }
        return ans;
    }

    void upDate(const vector<int>& v, int& ans){
        int temp=0;
        for(int i=0;i<v.size();++i){
            int min_height=INT_MAX;
            for(int j=i;j<v.size();++j){
                if(v[j]==0){
                    break;
                }
                else{
                    min_height=min(min_height,v[j]);
                    temp=max(temp,(j-i+1)*min_height);
                }
            }
        }
        ans=max(temp,ans);
    }
};
```
