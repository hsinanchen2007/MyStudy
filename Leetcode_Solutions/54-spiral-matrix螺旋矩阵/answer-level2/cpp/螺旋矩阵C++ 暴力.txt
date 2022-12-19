### 解题思路
简单的暴力解法，时间复杂度是O(m*n)，关键是如何判断何时停止。
因为多用++和--，所以看起来复杂但是执行用时不会很长。
![image.png](https://pic.leetcode-cn.com/143e0b461e51e8df5297679ac92c64cbeed4b4b36f64e5daec6c558834062bf7-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> re;
        int xMax=matrix.size();
        if(xMax==0)
            return re;
        int yMax=matrix[0].size();
        int x=0,y=-1;
        int high=0,low=0,left=0,right=0;
        while(true)
        {
            while(++y<yMax-right)
            {
                re.push_back(matrix[x][y]);
            }
            high++;
            if(high+low==xMax || left+right==yMax)
                break;
            y--;
            while(++x<xMax-low)
            {
                re.push_back(matrix[x][y]);
            }
            right++;
            if(high+low==xMax || left+right==yMax)
                break;
            x--;
            while(--y>=0+left)
            {
                re.push_back(matrix[x][y]);
            }
            low++;
            if(high+low==xMax || left+right==yMax)
                break;
            y++;
            while(--x>=0+high)    
            {
                re.push_back(matrix[x][y]);
            }
            left++;
            if(high+low==xMax || left+right==yMax)
                break;
            x++;
        }
        return re;
    }
};
```