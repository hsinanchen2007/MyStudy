### 解题思路
记录下机器人走第一个周期的序列表，然后将所有的情况回归到第一周期

### 代码

```cpp
class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        //int queue[command.size()] = {0};
        int coffe_x[command.size()+2] = { 0 };
        int add = 0;
        for (int i = 1; i < command.size() + 1; i++)
        {
            //if(command[i] == 'U') queue[i] = 1;
            coffe_x[i] = coffe_x[i - 1];
            if (command[i - 1] == 'R')
            {
                //queue[i] = -1;
                ++add;           //记录X方向一共走了多少步，这样可以推出Y方向
                coffe_x[i] = add;//记录X方向步行表
            }
            cout << "i:" << coffe_x[i] << endl;
        }
        int t=0, t1 = 0,t2 = 0;
        int sum = 0;
        int temp = 0;
        int i = 0, j = 0;
        cout << "size" << obstacles.size() << endl;
        while (i < obstacles.size())
        {
            sum = 0;
            if (obstacles[i][0] <= x && obstacles[i][1] <= y)
            {
                t=0;
                t = (obstacles[i][0]+obstacles[i][1])/command.size();
                cout << "t:" << t << endl;
                obstacles[i][0] = obstacles[i][0] - t * add;
                obstacles[i][1] = obstacles[i][1] - t * (command.size() - add);//回归到第一个周期中
                sum = obstacles[i][0] + obstacles[i][1];//表示目前走了多少步
                cout << i << endl;
                cout << "x1:" << obstacles[i][0] << "  y1:" << obstacles[i][1] << endl;
                if(obstacles[i][0]<0 || obstacles[i][1]<0) 
                {
                    i++;
                    continue;
                }
                if (obstacles[i][0] == coffe_x[sum] && obstacles[i][1] == (sum - coffe_x[sum]))
                {
                    return false;
                }
            }
            i++;
        }
        t = (x+y)/command.size();
        x = x-t*add;
        y = y - t * (command.size() - add);
        cout << "x:" << x << "  y:" << y << endl;
        sum = x+y;
        if(x<0 || y<0)
        {
            cout << 0 << endl;
            return false; 
        }
        if (x == coffe_x[sum] && y == (sum - coffe_x[sum])) 
        {
            cout << 1 << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
};
```