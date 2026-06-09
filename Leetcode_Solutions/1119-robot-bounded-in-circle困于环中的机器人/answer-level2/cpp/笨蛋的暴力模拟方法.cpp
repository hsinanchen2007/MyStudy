 机器人的运动只有四个方向， {1， 0} ，{0， 1} ， {-1， 0}， {0， -1}
每一次的转向，到下一次的直走，都可以找到一个对应的元组， 为'G'或'L'的时候，就在元组里面进行寻找
为'R'时，当前状态为向北， 所以向右转时刚好就是在x轴的正方向上进行，所以找到对用的方位，

```
class Solution{
public:
    bool isRobotBounded(string instructions){
        int x = 0;
        int y = 0;
        int i = 0;
        int dir[][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};// 上下左右四个方向，
        do{
            for(auto ch : instructions)
            {
                if(ch == 'G')
                {
                    /// 两个方向x, y
                    x+=dir[i][0];
                    y+=dir[i][1]; 
                }
                else if(ch == 'R')
                {
                    // 初始状态是在向北，如果第一次右转，会发现下一次直走 就是x+1; 再转一次就是y-1, 再转一次就是x-1； 就可以通过这个规律来构建一个二维数组，每一次的方向转换都用来定位是第几个状态，需要用到第几个元祖
                    ++i;
                    i%=4;
                }
                else
                {
                    (i+3)%4;
                }
            }
        }
        while(i!=0);
        if(x==0 && y == 0)
            return true;
        return false;
    }
    
};
```
