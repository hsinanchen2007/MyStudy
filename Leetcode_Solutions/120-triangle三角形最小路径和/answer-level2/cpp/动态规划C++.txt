### 解题思路
将每一层每一个结点的值更新为到此节点经历的最短路径

### 代码

```cpp
class Solution {
public:
    int length;
    int minimumTotal(vector<vector<int>>& triangle) {
        length=triangle.size();
        if(length==0) return 0;
        if(length==1) return triangle[0][0];
        triangle[1][0]+=triangle[0][0];
        triangle[1][1]+=triangle[0][0];
        for(int i=2;i<length;++i){
            triangle[i][0]+=triangle[i-1][0];
            for(int j=1;j<i;++j)
                triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            triangle[i][i]+=triangle[i-1][i-1];
        }
        int min=triangle[length-1][0];
        for(int i=1;i<length;++i){
            if(triangle[length-1][i]<min)
                min=triangle[length-1][i];
        }
        return min;
    }
};
```