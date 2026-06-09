### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        if(matrix.size() ==0){
            return {};
        }
        int width=matrix[0].size();
        int height=matrix.size();
        int t=0;
        while(res.size()<width*height){
            switch(0){
            case(0):
            {
                if(res.size()<width*height){
                    for(int i=t,j=t;j<width-t;j++){
                res.push_back(matrix[i][j]);
                }
                }else{
                    return res;
                }
                
            }
            
            case(1):
            {
                if(res.size()<width*height){
                    for(int i=t+1,j=width-t-1;i<height-t;i++){
                    res.push_back(matrix[i][j]);
                }
                }else{
                    return res;
                }
            }
            
            case(2):
            {
                if(res.size()<width*height){
                    for(int i=height-t-1,j=width-t-2;j>=t;j--){
                    res.push_back(matrix[i][j]);
                }
                }else{
                    return res;
                }

            }
            
            case(3):
            {
                if(res.size()<width*height){
                    for(int i=height-t-2,j=t;i>=t+1;i--){
                    res.push_back(matrix[i][j]);
                }
                }else{
                    return res;
                }
            
            }
            
            t++;
            }
        }
        
           return res;
            
        
    }
}; 
