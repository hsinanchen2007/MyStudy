### 解题思路
思路比较直接（虽然代码有点冗长），就是看`blocked`方块是否包围了源点或目标点。
#### 具体思路：
1、看题目限制条件。`0 <= blocked.length <= 200` 表明，如果从 `blocked` 方块入手，所花的时间会比较少。
2、把相邻的 `blocked` 方块看成一块联通区域。
3、每个联通区域都有其边界。如果某条边界包围了源点或目标点，则路径被封锁；反之，则没被封锁。具体看下面几个图：
![image.png](https://pic.leetcode-cn.com/50e204e81023f19cfe1797d03b54b5526ff495b5eb51e3e2aa4d75499af0dcb1-image.png)
（`blocked`的边界没有包围原点，从源点可以另找路径到达目标）
![image.png](https://pic.leetcode-cn.com/93bf6173b9eb328cc8503a4739cf53558559aaa0e76cb4a4579aa08047fbcee2-image.png)
（`blocked`的一条内边界包围了源点，从源点无法到达目标）
![image.png](https://pic.leetcode-cn.com/48d3b4dd2691b18ef1795483e13d68b0e093863b872111e612974dcb416f17b0-image.png)
（`blocked`的一条内边界和迷宫边界共同包围了源点。从源点无法到达目标）
4、从图中可以看出，如果边界包围了源点/目标点，则其 **穿越** 从源点到目标点的 **任一路径** **奇数次**；否则，一定穿越了**偶数次**。
5、因此大概思路就是这样：
    S1、首先沿着从源点到目标点的某一路径走。
    S2、如果遇到了障碍物点，则沿着障碍物的边界走，在这过程中计算其穿越路径的次数。
    S3、
    ->如果穿越路径的次数为奇数，则该障碍物的边界封锁了源点/目标点，返回 False; 
    ->否则，则该障碍物没有封锁源点。然后沿着路径继续走，如果再碰到障碍物，则返回 S2 步骤继续搜索。
    ->如果走到了目标点还没碰到可以封锁的障碍物，则返回 True。
6、如何沿着障碍物的边界走看下图：
![image.png](https://pic.leetcode-cn.com/09255b15c7283bc96aa25d3dced5f6ae30eb7ba3a5522aaaec8d9d628cfbc3ee-image.png)

### 代码
```
注：代码实现比较繁琐。如果有大佬可以给出更简洁的实现，
欢迎在评论区评论（附上代码或给出自己的题解链接）。
```
![image.png](https://pic.leetcode-cn.com/65eb8d1452ec63c99e21d03999c176594d5c8d1d876380e3a1246df7e7da2e46-image.png)

```cpp
// 为了让尽可能多的人看懂代码，添加一些注释
// 代码实现还是有些复杂度的，我当初花了差不多一天的时间来实现，有些细节和方法需要考虑。
// 结合一个具体的情况说明代码。
//
//  //////////////////
//  ///|      BB
//  ///| [S]--BB---- 
//  ///|    BBB     | --- 从 S 到 T 的一条路径
//  ///|BBBBB       |
//  ///|           [T]
//
//  [S] - 源点 [T] - 目标点 B - 障碍物
//
//  上面说 "沿着从 S 到 T 的一条路径" 走，不是说就直接“选一条路径，然后沿着走”，肯定超时。
//  而是想象一条虚拟的路径（如上图，先从 S 走到 T 的上方，然后再走到 T。）
//  然后，把所有障碍物点按照坐标顺序排序。（先 x 从小到大，相等时 y 从小到大）
//  再从头遍历所有的障碍物点（B）。从图上走一遍，看哪个 B 先与“虚拟路线”相遇。
//  看出来了吗，这样第一个和“虚拟路线”相遇的点一定是从 S 到 T 所遇到的第一个障碍物。
//
//  然后，从这个相遇的 B 出发, 向两侧进发。看总共穿越了多少次“虚拟路线”。
//  如下图所示，搜索的就是这条线(下图标 X 的位置)
//
//  //////////////////
//  ///|      XB
//  ///| [S]--XB---- 
//  ///|    XXB     |
//  ///|XXXXB       |
//  ///|           [T]
// 
//  那么，如果判断搜索路线穿越了“虚拟路线”? 首先，将整个地图按照 “虚拟路线” 分成两个区域：
//
//  //////////////////
//  ///|          AREA-B
//  ///| [S]-------- 
//  ///|  . . . . . | 
//  ///|  . AREA-A. |
//  ///|  . . . . .[T]
//
//  AREA-A 为虚拟路线“左下方”的部分，AREA-B 为其余部分(不包括虚拟路线）。
//  [判断区域归属由宏 AREA 负责]。
//  一条穿越了“虚拟路线”的搜索路线如下图所示：
//  
//        X
//        X   AREA-B
//   [S]--X------------[T] 
//       X   AREA-A
//
//  可见，搜索路线必有 1 个点在 A 区，另 1 个点在 B 区，还有 1 个点在“虚拟路线”上。
//  就这个例子来说，我们从在 “虚拟路径”上的 "X" 开始搜索。首先向上，然后向下，
//  发现两个点在不同区域，并且搜索开始的点就在“虚拟路径”上，满足上述条件。
//  这样，穿越次数 + 1。
//  [判断点是否在 “虚拟路线” 上由宏 INPATH 负责]。
//
//  下面完整地叙述程序的运行情况：
//
//  A. 就是上面的例子。
//     程序从 @ 处开始搜索，X为搜索路线。向上到边，向下到边，总共 1 次穿越。封锁成功。
//  //////////////////
//  ///|      XB
//  ///| [S]--@B----
//  ///|    XXB     |
//  ///|XXXXB       |
//  ///|           [T]
//
//  B. 程序从 @ 处开始搜索，X为搜索路线。从图上走一遍，向上搜索，向下搜索都到达同一个
//     边界。总共 2 次穿越。封锁失败。
//     另外, 由于搜索过后，包在 “X” 中的 “B” 再也没有用了（不能封锁），后续的搜索，
//     选择横坐标在 “extidxx” 之后的点开始即可。“extidxy” 作用类似。
//  //////////////////
//  ///|           extidxx
//  ///|             |
//  ///|         XXX |   
//  ///| [S]----@BBBXX----- 
//  ///|       XBBBBBX     | 
//  ///|     XXXXXXXX      |
//  ///| XXXX             [T]
//  
//  
class Solution {
public:
    class Point
    {
        public:
        int x;
        int y;
        bool operator< (const Point& right) const
        {
            if(this->x < right.x)
                return true;
            else if(this->x == right.x)
                return this->y < right.y;
            else
                return false;
        }
        Point(const int x,const int y)
        {
            this->x = x;
            this->y = y;
        }
    };

    int x1,y1,x2,y2,minx,maxx,miny,maxy,l,r;
    int extidxx, extidxy;
    set<Point> pts;

    // (x1,y1)            (x2,y2)
    // S--------  |          T
    //         |  |          |
    //         |  |          |
    //         T  | S---------
    //     (x2,y2)  (x1,y1)
    #define INPATH(x,y) (((x) == (x2) && (y) <= maxy && (y) >= miny) || ((y) == (y1) && (x) >= minx && (x) <= maxx))
    #define AREA(x,y) (((x) > maxx) || ((y2 > y1)? ((y) < miny) : ((y) > maxy)))
    #define INBOARD(x,y) ((x) >= l && (x) <= r && (y) >= l && (y) <= r)

    void updateExt(const Point& pt)
    {
        extidxx = max(pt.x, extidxx);
        if(y2 < y1) extidxy = min(pt.y, extidxy);
        else extidxy = max(pt.y, extidxy);
    }

    bool notSearched(const Point& pt)
    {
        if(pt.x > extidxx)
            return true;
        if(y2 < y1 && pt.y < extidxy)
            return true;
        if(y2 > y1 && pt.y > extidxy)
            return true;
        return false;
    }

    enum SEARCHRES
    {
        LOCKED = 0,
        UNLOCKED = 1,
        REACHEDGE = 2
    };

    SEARCHRES search(
        Point cpt, // 搜索起始点
        int rotate, // 旋转方向
        int lastarea, // 第一次搜索时应为 0, 第二次为 outarea
        int & crosses, // 穿越数, 初始化值为 0
        int & outarea // 首次穿出的区域, 初始化值为 0
    )
    {
        const int xoffs[] = {0,1,1, 1, 0,-1,-1,-1};
        const int yoffs[] = {1,1,0,-1,-1,-1, 0, 1};
        const int oppomove[] = {4,5,6,7,0,1,2,3};

        Point firstpt = cpt;

        // 搜索起始方向, 当 y == y1 时应为 6(←), 否则若 y2 < y1 应为 0(↓); 若 y2 > y1 应为 4(↑).
        int currmove = (cpt.y == y1) ? 6 : ((y2 < y1)? 0 : 4);

        // 上次搜索的点是否在线内
        bool lastIn = true;

        for(;;)
        {
            // 找到搜索起始方向 = 前一个方向的对向
            bool foundNew = false;

            // 八联通方向搜索(四联通移动,八联通即可封锁)
            for(int i = 0; i < 8; ++i)
            {
                currmove += rotate;
                if(currmove >= 8)
                    currmove -= 8;
                else if(currmove <= 0)
                    currmove += 8;

                Point npt(cpt.x + xoffs[currmove], cpt.y + yoffs[currmove]);

                if(npt.x == firstpt.x && npt.y == firstpt.y)
                {
                    // 返回了初始点，绕了回来
                    // 如果出的方向与进的方向不同, 则算作一次穿越
                    if(abs(lastarea - outarea) == 2)
                        crosses += 1;
                    if((crosses & 1) == 0) // 偶数次, 没包起来
                        return UNLOCKED;
                    else // 奇数次, 把原点 or 目标点 包了起来
                        return LOCKED;
                }
                else if(!INBOARD(npt.x,npt.y))
                {
                    int currArea = AREA(npt.x,npt.y) ? 1 : -1;
                    if(abs(lastarea - currArea) == 2 && lastIn)
                        crosses += 1; // 两次在不同半区且经过原始路线算作穿越
                    lastarea = currArea;
                    if(outarea == 0)
                        outarea = currArea;
                    lastIn = false;
                    return REACHEDGE;
                }
                else
                {
                    set<Point>::iterator it = pts.find(npt);
                    if(it != pts.end())
                    {
                        foundNew = true;

                        if((!INPATH(it->x,it->y)))
                        {
                            int currArea = AREA(it->x,it->y) ? 1 : -1;
                            if(abs(currArea - lastarea) == 2 && lastIn)
                                crosses += 1; // 两次在不同半区且经过原始路线算作穿越
                            lastarea = currArea;  
                            if(outarea == 0)
                                outarea = currArea;
                            lastIn = false;
                        }
                        else
                        {
                            lastIn = true;
                            updateExt(npt);
                        }
                        
                        cpt = *it;
                        currmove = oppomove[currmove] + rotate;
                        break;
                    }
                }
            }

            if(!foundNew)
                return UNLOCKED; // 孤点, 不能起到封锁作用
        }
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        l = 0, r = 1e6 - 1;
        x1 = source[0], y1 = source[1], x2 = target[0], y2 = target[1];
        minx = min(x1,x2), maxx = max(x1,x2), miny = min(y1,y2), maxy = max(y1,y2);

        if(x2 < x1)
        {
            // 交换 source 和 target
            int tmp = x1; x1 = x2; x2 = tmp;
            tmp = y1; y1 = y2; y2 = tmp;
        }

        extidxx = x1, extidxy = y1;

        this->pts.clear();
        for(vector<int> b :blocked)
        {
            if(pts.find(Point(b[0],b[1])) == pts.end())
                pts.insert(Point(b[0],b[1]));
        }

        set<Point>::iterator it = pts.begin();
        set<Point>::reverse_iterator rit = pts.rbegin();

        for(;;)
        {
            // 在初始路径上找到起始点
            Point cpt(0,0);

            // 当 y2 < y1 且 x 走到 x2 时, y 应当沿着 y减小 的方向走
            if(extidxx == x2 && y2 < y1)
            {
                for(;; ++rit)
                {
                    if(rit == pts.rend())
                        return true;
                    if(INPATH(rit->x, rit->y) && notSearched(*rit))
                    {
                        updateExt(*rit);
                        cpt = *rit;
                        break;
                    }
                }
            }
            else // 否则应沿着 x 增大 或 y 增大 的方向走
            {
                for(;; ++it)
                {
                    if(it == pts.end())
                        return true;
                    if(INPATH(it->x, it->y) && notSearched(*it))
                    {
                        updateExt(*it);
                        cpt = *it;
                        break;
                    }
                }
            }

            int crosses = 0, outarea = 0, t = 0;

            // 正向搜索
            SEARCHRES res = search(cpt,1,0,crosses,outarea);

            if(res == UNLOCKED)
                continue;
            else if(res == LOCKED)
                return false;
            
            //REACHEDGE,则再进行反向搜索
            res = search(cpt,-1,outarea,crosses,t);

            if(res == UNLOCKED)
                continue;
            else if(res == LOCKED)
                return false;
            
            if(crosses & 1)
                return false;
        }

        return true;
    }
};
```