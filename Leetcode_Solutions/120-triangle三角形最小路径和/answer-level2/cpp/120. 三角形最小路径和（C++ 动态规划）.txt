# 120. 三角形最小路径和
修改原来的二维数组，从下至上修改数组为`本身+左右相邻节点的最小值`
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for( int i = triangle.size()-2; i >= 0; --i ){
        	for( int j = triangle.at(i).size()-1; j >= 0; --j ){
        		triangle[i][j] = triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);
        	}
        }
        return triangle[0][0];
    }
};
```
