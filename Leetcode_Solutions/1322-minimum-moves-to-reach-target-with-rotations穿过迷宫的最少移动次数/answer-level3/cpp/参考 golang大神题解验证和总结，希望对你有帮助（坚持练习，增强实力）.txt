1、先说为什么DFS不行
   1）DFS需要遍历全部解再比较，取出走最少路径的，耗时长，一定为会超时（最多过了17个用例）
   2）采用3维数组记录已经走过的方向和位置行不行？ flagDB[y][x][水平/垂直]，不行
      因为如果慢的（步数用的多）一种搜索方式在前面（因为深度优先）走到目的地了，后边遍历到快的路径到此处时，就会直接返回不走了；
      因此无法保障结果是最优解；
   3）BFS为什么可以，它是怎么保障能取到最优解的？ 因为BFS每次循环，都把“一层”能走的都走完，先走到目的地的当然是最快的1个；
      一层是什么意思？是它可以往下走的3种情况（实际操作对应把3种情况入队列）；为什么要用队列？队列保障每次走一层，有序前进
![image.png](https://pic.leetcode-cn.com/fb7fdc18d74b4191207462e7288ce70c9f031c8c8f1df84fda472296ce1e2856-image.png)

2、数据结构
   1）队列queue
   2）自己定义的Nodest，3个成员y, x, flag; flag：0表示水平 flag：1 表示垂直
   3）大数组flagDB[100][100][2]，表示flagDB[y][x][flag] 蛇头结点的位置和方向是否走过了，1表示走过了不需要再走了（去重）
3、出口条件
   1）找到最下角的位置，且是水平状态表示到达目的地，直接返回step，如果没找到，最终返回-1；
   2）如何计算步数，每次一层遍历完，对应for循环走完，step++；


![image.png](https://pic.leetcode-cn.com/2aee3010e76819bbaa716c9f5955b2c9f318917b4dfa536e0ca4b74d4ee450bb-image.png)
![image.png](https://pic.leetcode-cn.com/3f85e7ae0fe1ec55fcdc06c50c0e6b36ac85761c1c9523a2682d6812fb5b21aa-image.png)
![image.png](https://pic.leetcode-cn.com/a0bece669e4195a63244be265524796b398581e43fd07253fb21ca3c69dc1e08-image.png)
![image.png](https://pic.leetcode-cn.com/c412d77f538183f056b0911d95d1fd126eee1e8c04a11125ef75d9c77c42aff8-image.png)

```
#define SHP 0
#define CHZH 1
class Nodest {
public:
    int y;
    int x;
    bool flag;
    Nodest(int a, int b, int c): y(a), x(b), flag(c) {}
};

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) 
    {  
        int step = 0; 
        int yNum = grid.size();
        int xNum = grid[0].size();
        int flagDB[100][100][2] = {0};
        memset(flagDB, 0, size(flagDB));
        
        Nodest node(0,1,SHP);
        queue<Nodest> qu;
        qu.push(node);
    
        while (qu.size() != 0) {
            int quSize = qu.size();
            for (int i = 0; i < quSize; i++) {
                Nodest tmp = qu.front();
                qu.pop();                
                if (tmp.y == yNum - 1 && tmp.x == xNum - 1 && tmp.flag == SHP) {
                    return step;
                }    
                // 水平
                if (tmp.flag == SHP) {
                    // 向右
                    Nodest tmp1(tmp);
                    tmp1.x += 1;
                    if (tmp1.x < xNum && grid[tmp1.y][tmp1.x] == 0) {
                        if (flagDB[tmp1.y][tmp1.x][SHP] == 0) {
                            flagDB[tmp1.y][tmp1.x][SHP] = 1;
                            tmp1.flag = SHP;
                            qu.push(tmp1);
                        }
                    }
                    // 向下
                    tmp1 = tmp;
                    tmp1.y += 1;
                    if (tmp1.y < yNum && grid[tmp1.y][tmp1.x] == 0 && grid[tmp1.y][tmp1.x -1] == 0) {
                        if (flagDB[tmp1.y][tmp1.x][SHP] == 0) {
                            flagDB[tmp1.y][tmp1.x][SHP] = 1;
                            tmp1.flag = SHP;
                            qu.push(tmp1);
                        }

                    }
                    // 顺时针旋转
                    tmp1 = tmp;
                    if (tmp1.y < yNum - 1 && grid[tmp1.y + 1][tmp1.x] == 0 && grid[tmp1.y + 1][tmp1.x - 1] == 0) {
                        if (flagDB[tmp1.y + 1][tmp1.x - 1][CHZH] == 0) {
                            flagDB[tmp1.y + 1][tmp1.x - 1][CHZH] = 1;
                            tmp1.y += 1;
                            tmp1.x -= 1;
                            tmp1.flag = CHZH;
                            qu.push(tmp1);
                        }
                    }
                } else if (tmp.flag == CHZH) { // 垂直
                    // 向右
                    Nodest tmp1(tmp);
                    tmp1.x += 1;
                    if (tmp1.x < xNum && grid[tmp1.y][tmp1.x] == 0 && grid[tmp1.y -1][tmp1.x] == 0) {
                        if (flagDB[tmp1.y][tmp1.x][CHZH] == 0) {
                            flagDB[tmp1.y][tmp1.x][CHZH] = 1;
                            tmp1.flag = CHZH;
                            qu.push(tmp1);
                        }
                    }
                    // 向下
                    tmp1 = tmp;
                    tmp1.y += 1;
                    if (tmp1.y < yNum && grid[tmp1.y][tmp1.x] == 0) {
                        if (flagDB[tmp1.y][tmp1.x][CHZH] == 0) {
                            flagDB[tmp1.y][tmp1.x][CHZH] = 1;
                            tmp1.flag = CHZH;
                            qu.push(tmp1);
                        }
                    }
                    // 逆时针
                    tmp1 = tmp;
                    if (tmp1.x < xNum - 1 && grid[tmp1.y][tmp1.x + 1] == 0 && grid[tmp1.y - 1][tmp1.x + 1] == 0) {
                        if (flagDB[tmp1.y - 1][tmp1.x + 1][SHP] == 0) {
                            flagDB[tmp1.y - 1][tmp1.x + 1][SHP] = 1;
                            tmp1.y -= 1;
                            tmp1.x += 1;
                            tmp1.flag = SHP;
                            qu.push(tmp1);
                        }
                    }
                }                 
            }
            step++;
        }
        return  -1;
    }
};
```




