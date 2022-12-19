这题题目比较长，通过图来解读一下

![图像渲染.png](https://pic.leetcode-cn.com/1ef5d3aaa18f5f26945c4ff1892f69a0a22b83aa1cf7825373d0f44d101bef4b-%E5%9B%BE%E5%83%8F%E6%B8%B2%E6%9F%93.png)

本题的目的是在图像中，用新的色块代替旧的色块，图像中或许有一个以上相同颜色的色块，但是只改变输入希望改变的其中一个色块

例如，假设图像中，输入给的目标点位于黄色块1中，那么我们遍历黄色块1的所有像素，并用新的颜色代替它们，而黄色块 2，3，则不改变。

这题类似于 [力扣：岛屿的数量](https://leetcode-cn.com/problems/number-of-islands/) 。差别在于，岛屿的数量要将图中的所有点全部遍历一遍，而本题只需要遍历目标点所在的色块

这里使用 BFS 来实现，用 DFS 同样也可

最后，由于其中一个测试用例的新旧颜色相同，所以需要剪枝，若新旧颜色相同，直接返回原图像。
```
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue <pair<int,int>> olds;
        int old = image[sr][sc];
        if(newColor == old) return image; //剪枝，若新颜色和旧色一样，直接返回原来的图像
        olds.push({sr,sc});
        //BFS由此开始--------------
        while(!olds.empty()) 
        {
            pair<int,int> temp = olds.front();
            olds.pop();
            image[temp.first][temp.second] = newColor; //因为放入队列中的像素都是旧色像素，直接变成新色
            vector<pair<int,int>> around = {{0,1},{0,-1},{-1,0},{1,0}}; //该像素四周的像素
            for(int i = 0; i < 4; ++i) 
            {
                int y = temp.first + around[i].first;
                int x = temp.second + around[i].second;
                if(0 <= y && y < image.size() && 0 <= x && x < image[0].size() && image[y][x] == old) //若在图像内，且是旧色，则压入olds队列
                    olds.push({y,x});
            }
        }
        return image;
    }
};
```