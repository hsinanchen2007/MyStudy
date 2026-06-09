```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int down=matrix.size()-1;
        vector<int> ans;
        if(down<0)
            return ans;
        int right=matrix[0].size()-1;
        int up=0;
        int left=0;
        int count=0,target=(down+1)*(right+1);
        while(count<target){
            for(int i=left;i<=right;++i){
                ans.push_back(matrix[up][i]);
                ++count;
                if(count==target)
                    return ans;
            }
            ++up; 
            for(int i=up;i<=down;++i){
                ans.push_back(matrix[i][right]);
                ++count;
                if(count==target)
                    return ans;
            }
            --right;  
            for(int i=right;i>=left;--i){
                ans.push_back(matrix[down][i]);
                ++count;
                if(count==target)
                    return ans;
            }
            --down;
            for(int i=down;i>=up;--i){
                ans.push_back(matrix[i][left]);
                ++count;
                if(count==target)
                    return ans;
            }
            ++left;
        }
        return ans;  
    }
};

```
