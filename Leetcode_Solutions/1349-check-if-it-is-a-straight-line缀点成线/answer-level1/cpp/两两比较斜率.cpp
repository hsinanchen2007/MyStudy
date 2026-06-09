![image.png](https://pic.leetcode-cn.com/8c2e3a10bdc7be4e958091ad6353a24932bd493d984163459a6434a4ae0e9569-image.png)

```
class Solution {
public:
    bool checkStraightLine(vector<vector<int> >& coordinates) {
        int flag=1;//flag=1，表示为直线 
	double k,tmp;
        double x=coordinates[1][0]-coordinates[0][0];
        double y=coordinates[1][1]-coordinates[0][1];
        k=y/x;//前两点的斜率
        for(int i=2;i<coordinates.size();i++){
        	x=coordinates[i][0]-coordinates[i-1][0];
        	y=coordinates[i][1]-coordinates[i-1][1];
        	tmp=y/x;
        	if(tmp!=k){
        		flag=0;
        		break;
			}
		} 
		return flag;
    }
};
```
