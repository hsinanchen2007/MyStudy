```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows==0)
            return ans;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                //若是左右两边的边界，则一个一个赋值
                if(j==0||j==i){
                    ans[i].push_back(1);
                }
                //否则等于左上角的值加右上角的值
                else{
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
        }
       return ans; 
    }
};
```