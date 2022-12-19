### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0){return false;}
        int n=matrix[0].size();
        if(n==0){return false;}

        int i=m-1;
        int j=n-1;
        while(i>=0&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            if(matrix[i][j]>target){
                i--;
                j--;
            }else{
                break;
            }
        }
        i=(i<0?0:i);
        j=(j<0?0:j);
        
        int x,y,middle;
        for(int a=i;a>=0;a--){
            x=j;
            y=n-1;
            while(x<=y){
                middle=(x+y)/2;
                if(matrix[a][middle]==target){
                    return true;
                }
                if(matrix[a][middle]>target){
                    y=middle-1;
                }else{
                    x=middle+1;
                }
            }
        }
        for(int a=i;a<m;a++){
            x=0;
            y=j;
            while(x<=y){
                middle=(x+y)/2;
                if(matrix[a][middle]==target){
                    return true;
                }
                if(matrix[a][middle]>target){
                    y=middle-1;
                }else{
                    x=middle+1;
                }
            }
        }
        return false;
    }
};
```