### 解题思路
从0,0出发，可以简单发现如下规律：

下标x，y的和，如果是2的倍数，是朝右上，则x--；y++然后考虑右边界和上边界的情况即可。
如果不是2的倍数，是朝左下，则x++；y--然后考虑左边界和下边界的情况即可。

结束条件即到右下角。
### 代码

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
       vector<int> xx;
           if(matrix.empty()) return xx;

        int lie=matrix[0].size();//列
        int hang=matrix.size();//行
     
        int x=0,y=0;
        while(1){
            if(x<0) x=0;//如果xy发生越界，使其回来
            if(x>hang-1) x=hang-1;
            if(y<0) y=0;
            if(y>lie-1) y=lie-1;
            
            xx.push_back(matrix[x][y]);
            if(x==hang-1&&y==lie-1) break;
            
            else if((x+y)%2==0){//该点右上指
          
			    x--;y++;  //在上边界处，x越界，y指向正确
			    if(y>lie-1) x=x+2;//在右边界处，y越界，x向上指错一格，所以x向下两格
		
            }

             else if((x+y)%2!=0){//该点左下指
          
			    x++;y--; //在左边界，x指向正确，y越界
			    if(x>hang-1) y=y+2; //在下边界处，x越界，y向左指错一格，所以y向右两格
	        
            }
            
        }
        return xx;
    }
};
```