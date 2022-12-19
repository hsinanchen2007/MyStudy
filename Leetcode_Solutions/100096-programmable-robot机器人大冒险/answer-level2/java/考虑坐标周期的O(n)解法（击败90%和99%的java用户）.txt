## 思考过程：   
>刚上手拿到这题时以为只是简单的遍历，但看到3000+的通过次数就感觉事情好像不太对，果然不出所料连续三四次提交都接连失败（真实），一阵思考过后想到机器人的路径坐标可能是阶段性变化的，得到了这一解法，但在实现的时候又有了一些小插曲，我忽略了可能障碍物在终点之后的情形，导致第53个用例无法通过（第53个用例简直不是人写的！！变态的要死，感兴趣的可以把障碍物在终点之后的判断那一行注释掉提交，就可以看到了），但最终还是克服困难实现了这个方法，以下是解题思路。

## 解题思路：  
>我们不妨将机器人走完一次指令的过程看作一个周期，不难发现每一个周期间对应坐标的点存在关系x=x+p,y=y+q(其中(p,q)为第一次周期结束时机器人所处的坐标)，由这一规律可以得到第n个周期内的坐标方程：

                    x=x0+p*(n-1)
                    y=y0+q*(n-1)

>(其中（x0,y0）所求坐标在第一周期内的对应坐标，将机器人最开始的运动看作第一周期)
>所以我们只需要存储第一个周期内机器人走过的坐标就可以推算出该路径上的所有坐标，当需要判断机器人是否经过一个点时，我们只需确定这一点所在的周期，再使用已得的坐标方程遍历这一周期内的所有坐标即可，这样我们就将问题转化为了如何判断一个点所处的周期数。
>那么如何锁定一个已知点所处的周期数呢？我们可以通过比较周期内的最大点坐标（即（np,nq））与已知点坐标关系来判断。如果已知点的坐标大于第n-1周期的最大点而小于第n周期的最大点，则我们可以确定这一点处在第n周期内，我们也就可以比较轻易地确定这一点是否被机器人经过，从而判断了是否可达和是否碰撞。

## 复杂度：  
>时间复杂度：O(m*n)，其中m为指令长度，n为障碍坐标的个数，当指令长度很短或障碍坐标总位于周期起始时，时间复杂度为O(n)  
>空间复杂度：O(m)  
  
## 实现代码如下：  
```java []
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        char[] commands=command.toCharArray();
        int len=command.length();
        int[][] ways=new int[len][2];
        boolean couldarrive=false,isboom=false;
        //存储一个周期结束后机器人所处的坐标
        int p=0,q=0;
        //存储第一个周期内的所有坐标
        for(int i=0;i<command.length();i++){
            if(commands[i]=='U')
                q+=1;
            if(commands[i]=='R')
                p+=1;
            ways[i][0]=p;
            ways[i][1]=q;
        }
        int cycle;
        //判断该点是否可达，不可达直接返回false，不进行障碍物的判断
        for(cycle=0;;cycle++){
            if((cycle+1)*p>=x&&(cycle+1)*q>=y){
                for(int[]way:ways){
                    if(way[0]+cycle*p==x&&way[1]+cycle*q==y){
                        couldarrive=true;
                        break;
                    }
                }
                break;
            }
        }
        if(!couldarrive)
            return false;
        //进行机器人是否撞到障碍物的判断
        for(int[]obstacle:obstacles){
            //坑了我一个晚上的bug，不要忽略了障碍物可能在终点之后的判断
            //对那个变态用例感兴趣的就注释这个判断
            if(obstacle[0]>x||obstacle[1]>y)
                continue;
            for(cycle=0;;cycle++){
                if((cycle+1)*p>=obstacle[0]&&(cycle+1)*q>=obstacle[1]){
                    for(int[]way:ways){
                        if(way[0]+cycle*p==obstacle[0]&&way[1]+cycle*q==obstacle[1]){
                            return false;
                        }
                    }
                    break;
                }
            }
        }
        return true;
    }
}
```
##  提交结果：  
![批注 2020-01-18 145836.jpg](https://pic.leetcode-cn.com/3471a33b420591e83e026f9bae365707f15f6feb64a4a69bb59a6306ef2fea09-%E6%89%B9%E6%B3%A8%202020-01-18%20145836.jpg)
