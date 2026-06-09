### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool find(vector<vector<int>>& matrix,int x,int y,int target)
    {
        if(matrix[x][y]>matrix[matrix.size()-1][matrix[0].size()-1])
            return false;
        if(matrix[x][y]==target)return true;
        if(matrix[x][y]<target)
        {
            matrix[x][y]=matrix[matrix.size()-1][matrix[0].size()-1]+1;
            return false;
        }
        matrix[x][y]=matrix[matrix.size()-1][matrix[0].size()-1]+1;
        if(x>0&&y>0)
            return find(matrix,x-1,y,target)||find(matrix,x,y-1,target);
        else if(x>0)
            return find(matrix,x-1,y,target);
        else if(y>0)
            return find(matrix,x,y-1,target);
        else return false;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix.size()==0||matrix[0].size()==0)return false;
        //下面是暴力……这道题暴力好快啊我淦
        /*
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==target)
                    return true;
        return false;
        */
        return find(matrix,matrix.size()-1,matrix[0].size()-1,target);
    }
};
```