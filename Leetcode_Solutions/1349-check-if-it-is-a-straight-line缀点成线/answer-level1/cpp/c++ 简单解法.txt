解析都在代码注释中，请仔细看
```
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool isLine = true;
	    //取出前两个点
	    int x1 = coordinates[0][0];
	    int y1 = coordinates[0][1];
	    int x2 = coordinates[1][0];
	    int y2 = coordinates[1][1];
	    if (x1==x2){
	    	for (int i = 0; i < coordinates.size(); i++)
	    	{
                //如果前两个点x相等，就判断其它点的x是否都相等
	    		if (coordinates[i][0] != x1){
	    			isLine = false;
	    			return isLine;
	    		}
	    	}
	    }else
	    {
            //用前两个点定义一条直线,k=(y1 -y2)/(x1-x2),b=y-kx
	    	float k = (y1 -y2)/(x1-x2);
	    	float b = y1 - k*x1; 
	    	for (int i = 3; i < coordinates.size(); i++)
	    	{
                //判断其它点是否在这条直线即可y=kx+b
	    		if (coordinates[i][1] != k*coordinates[i][0] + b){
	    			isLine = false;
	    			return isLine;
	    		}
	    	}
	    }		 
	    return isLine; 
    }
};
```
