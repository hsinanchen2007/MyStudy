这一题没什么难度，但是要把代码写的好看，不能面向if else编程，写的又臭又长。
```
class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0||matrix[0].size()==0)
            return ans;
        int x =0,y=0,CurrentDir=0;
        while(ans.size()<matrix.size()*matrix[0].size()){
            if(x>=0&&x<matrix.size()&&y>=0&&y<matrix[0].size()&&matrix[x][y]!=INT_MIN){
                ans.push_back(matrix[x][y]);
                matrix[x][y]=INT_MIN;
            }
            else{
                x-=dir[CurrentDir][0];
                y-=dir[CurrentDir][1];
                CurrentDir=(CurrentDir+1)%4;
            }
            x+=dir[CurrentDir][0];
            y+=dir[CurrentDir][1];
        }
        return ans;
    }
};
```