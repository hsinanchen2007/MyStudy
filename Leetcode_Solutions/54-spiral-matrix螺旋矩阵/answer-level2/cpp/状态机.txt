![QQ图片20200330173557.png](https://pic.leetcode-cn.com/f5685a1ea10189dae8aed934097092cc42913b32079acd22866965b25eb9104d-QQ%E5%9B%BE%E7%89%8720200330173557.png)

### 解题思路
利用状态机，遍历方向在 → ↓ ← ↑四个方向之间切换。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;//保存结果
        vector<vector<int>> mark;//标记数组
        vector<vector<int>> wall;//结束数组
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            mark.push_back(vector<int>());
            wall.push_back(vector<int>());
            for(int j = 0 ; j < matrix[i].size() ; j++)
            {
                mark[i].push_back(0);
                wall[i].push_back(1);
            }
        }
        display(matrix,result,mark,wall);
        return result;
    }
    void display(vector<vector<int>> matrix,vector<int> &result,vector<vector<int>> &mark,vector<vector<int>>  wall)
    {
        //状态机
        const int right = 6;//右
        const int down = 2;//下
        const int left = 4;//左
        const int up = 8;//上
        int state;//初始状态
         int x = 0,y = 0;//起始点
         state = right;//先往右走
        while(mark != wall)//当mark全1时结束遍历
        {
            switch(state)
            {
                case right:
                    while(y < matrix[0].size() && mark[x][y] == 0)//坐标合法且标记合法
                    {
                        mark[x][y] = 1;//标记
                        result.push_back(matrix[x][y]);//保存值
                        y++;//继续往右走
                    }
                    y--;//不合法时退一步
                    x++;//往下走一步到新坐标    
                    state = down;//更换状态(开始往下走)
                break;
                case down:
                    while(x < matrix.size() && mark[x][y] == 0)
                    {
                        mark[x][y] = 1;
                        result.push_back(matrix[x][y]);
                        x++;
                    }
                    x--;
                    y--;
                    state = left;
                case left:
                    while(y >=0 &&mark[x][y] == 0)
                    {
                        mark[x][y] = 1;
                        result.push_back(matrix[x][y]);
                        y--;
                    }    
                    y++;
                    x--;
                    state = up;
                case up:
                    while(mark[x][y] == 0)//往上走不用担心坐标越界，只需判断标记数组
                    {
                        mark[x][y] = 1;
                        result.push_back(matrix[x][y]);
                        x--;
                    }    
                    x++;
                    y++;
                    state = right;
                default :
                break;
            }
        }
    }
};
```