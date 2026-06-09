class Solution {
    //递归方法补充函数
    void helper(vector<vector<int> >&matrix,int row,int col,int depth,vector<int>&ans,int min_len)
    {
        if((min_len&1)==1&&depth==min_len/2+1)
        {
            if(col>=row)
            {
                for(int i=depth-1;i<=col-depth;i++)
                    ans.emplace_back(matrix[depth-1][i]);
            }
            else
            {
                for(int i=depth-1;i<=row-depth;i++)
                    ans.emplace_back(matrix[i][depth-1]);
            }
            return;    
        }
        if((min_len&1)==0&&depth==min_len/2+1)return;
        for(int i=depth-1;i<=col-depth;++i)
        {
            ans.emplace_back(matrix[depth-1][i]);
        }
        for(int i=depth;i<=row-depth-1;++i)
        {
            ans.emplace_back(matrix[i][col-depth]);
        }
        for(int i=col-depth;i>=depth-1;--i)
        {
            ans.emplace_back(matrix[row-depth][i]);
        }
        for(int i=row-depth-1;i>=depth;--i)
        {
            ans.emplace_back(matrix[i][depth-1]);
        }
        helper(matrix,row,col,depth+1,ans,min_len);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //递归方法
        int row=matrix.size();
        if(row==0)return {};
        int col=matrix[0].size();
        if(col==0)return {};
        int min_len=min(row,col);
        vector<int> ans;
        helper(matrix,row,col,1,ans,min_len);
        return ans;
    }
};
