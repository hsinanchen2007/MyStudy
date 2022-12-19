每个确定距离下，坐标会有4种可能的情况。
逐渐增大距离，检查每个距离下的四种情况，直至矩阵中元素均被遍历。
```
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        int dist = 0;
        vector<int> mask(R*C, 0); 
        int sum = 0;
        while(sum < R*C)
        {
            for(int i = 0; i <= dist; ++i)
            {
                int j = dist - i;
                if( r0 + j >=0 && r0 + j < R && c0 + i >= 0 && c0 + i < C && !mask[(r0+j)*C+ c0+i])
                    {
                        result.push_back(vector<int>{r0+j, c0+i});
                        mask[(r0+j)*C+ c0+i] = 1;
                        sum++;
                    }
                if( r0 - j >=0 && r0 -j < R && c0 + i >= 0 && c0 + i < C && !mask[(r0-j)*C+ c0+i])
                    {
                        result.push_back(vector<int>{r0-j, c0+i});
                        mask[(r0-j)*C+ c0+i] = 1;
                        sum++;
                    }
                if(r0 + j >=0 && r0 + j < R && c0 - i >= 0 && c0 - i < C && !mask[(r0+j)*C+ c0-i])
                    {
                        result.push_back(vector<int>{r0+j, c0-i});
                        mask[(r0+j)*C+ c0-i] = 1;
                        sum++;
                    }
                if( r0 - j >=0 && r0 -j < R && c0 - i >= 0 && c0 - i < C && !mask[(r0-j)*C+ c0-i])
                    {
                        result.push_back(vector<int>{r0-j, c0-i});
                        mask[(r0-j)*C+ c0-i] = 1;
                        sum++;
                    }
            }               
            dist++;
        }
        return result;
    }
};
```
![屏幕快照 2019-12-31 14.11.53.png](https://pic.leetcode-cn.com/e125c8143fc4413f3e1e5ad847bc3ffc24c080d3c4bb9d588cb22518ddbf9fab-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-31%2014.11.53.png)
