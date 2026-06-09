```
class Solution {
public:
//每一个斜对角线进行排序一下，只需选取第一行，第一列就可以啦。。。
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int cur;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0&&j>0)continue;
                cur=0;
                ans.clear();//每一次必须清理一下
                int row=i,col=j;
                while(row<n&&col<m){//放入数组进行排序
                    ans.push_back(mat[row++][col++]);
                    //row++,col++;
                }
                sort(ans.begin(),ans.end());
                row=i,col=j;
                while(row<n&&col<m){//将排序好的对角线元素再放回去
                    mat[row++][col++]=ans[cur++];
                    //row++,col++,cur++;
                }
                
            }
        }
        return mat;
    }
};
```
