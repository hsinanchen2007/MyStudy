### 思路一

前天做比赛，一开始思路很直接：

**沿机器人的行走路线从起始位置走到终点，查看是否遇到障碍物，然后返回 true 或 false。**

正如大家预料到的是，超时了，很悲催。

这才发现没有注意题目给的终点范围超级大：

**0 <= x <= 1e9, 0 <= y <= 1e9**

这才反应过来应该重新找出路


### 思路二

首先想到 **问题1：在不使用思路一暴力法的前提下，根据给定的指令，机器人能不能到达终点，而不是擦肩而过？**

于是想到机器人是按照指令，循环规律地前进。

指令 “URR” 执行完毕停留在（2,1）这个点，假若终点是（10000,5001），那么机器人执行 5000 次指令到达终点附近的点（10000，5000），于是判断是否经过终点就很容易了。

```
// 判断机器人会不会走到终点（x, y）
bool helper(string command, int x_1, int y_1, int x, int y){
        // （x_1, y_1）是执行一遍指令第一次歇脚的位置

        int x_0 = 0, y_0 = 0, k = 0;
        
        // k 计算执行多少轮命令后即将到达终点（下一轮执行肯定能到）
        // 编译器警告我存在除0的现象，所以写了4个if-else，
        if (x_1 != 0 && y_1 != 0)
            k = min(x / x_1, y / y_1); 
        else if(x_1 == 0)
            k = y / y_1;
        else if(y_1 == 0)
            k = x / x_1;
        else
            return true;          
        
        // 相当于把终点坐标拿到原点附近，（注意同乘的k值必须相同，在这小栽了一把）
        x = x - k * x_1;
        y = y - k * y_1;
        
        // 判断下一轮是否会碰到终点
        for (int i=0; i<command.size(); ++i){
            if (x_0 == x && y_0 == y)
                return true;
            
            if (command[i] == 'U')
                ++y_0;
            else
                ++x_0; 
        }

        return false;
    }
```

**第二个问题：障碍物会不会成为 “绊脚石”？**

障碍物数量不是很多：
***0 <= obstacles 的长度 <= 1000***

既然也不能使用暴力法求行走的路上有没有碰到障碍物，换个角度可以求每个障碍物在不在行进的路上。

考虑一下就会发现，可以把障碍物视为机器人想要到达的终点，然后用刚才的方法来解决，代码都不用改，nice！
```
helper(command, x_1, y_1, obstacle_x, obstacle_y) == true/false (伪代码)
```


主代码实现是这样
```
bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int n = command.length();
        int x_1 = 0, y_1 = 0;
        
        // 计算第一次歇脚坐标（x_1, y_1），放在主代码就不会反复执行了
        for (int i=0; i<n; ++i){
            if (command[i] == 'U')
                ++y_1;
            else if (command[i] == 'R')
                ++x_1;           
        }
        
        // 如果终点坐标无法到达，直接判断失败即可
        if (helper(command, x_1, y_1, x, y) == false)
            return false;
        
        // 遍历所有障碍点，判断遇到终点前会不会碰到它们
        // 注意：判断前要加限制条件：障碍点 x, y 坐标均不能大于终点，因为机器人只能向上走、向右走，一旦超过了坐标就不再考虑该障碍点
        //（当时在此处又栽了一把，表现为例3没有通过测试）。
        for (int i=0; i<obstacles.size(); ++i){
            int x_obs = obstacles[i][0];
            int y_obs = obstacles[i][1];

            if (x_obs<=x && y_obs<=y && helper(command, x_1, y_1, x_obs, y_obs) == true){
                return false;                
			}
        }
        return true;
    }
    
```
**时间复杂度：**$O(comand.length() * obstacles.size())$
最差情况下，对于每一个障碍物都需要执行一遍 command 指令。

**空间复杂度：** $O(1)$
只设置了常量，没有开辟新的空间。



![1569514070(1).png](https://pic.leetcode-cn.com/473fa66986785b199de2a5eba647e660d874567b03e921d5bea0fbdd84e6ca59-1569514070\(1\).png){:width=350}