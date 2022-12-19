```
class Solution {
    //y = ax +b;
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double a =0,b=0;

        int temp=1;
        if (coordinates[0][0] == coordinates [1][0]){
            for(int j =1;j<coordinates.size();j++){
                if(coordinates[j][0]!=coordinates[j-1][0]){
                    temp =0;
                    break;
                }
            }
        }else{
            a = (coordinates[0][1]-coordinates[1][1])/(coordinates[0][0]-coordinates[1][0]);
            b = (coordinates[0][1]-a*coordinates[0][0]);
            for(int i =0;i<coordinates.size();i++){
                if(coordinates[i][1] !=a *coordinates[i][0]+b ){
                    temp= 0;
                    break;
                }
            }

        }
        
        
            
    
        
        return temp;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4dbb2c6c4758ca80ec13479a87be73b25962746e0a34136b3fcb2ad7b78ec47f-image.png)
