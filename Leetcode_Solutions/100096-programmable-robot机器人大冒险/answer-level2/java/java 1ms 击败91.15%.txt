### 解题思路
- 1.在障碍物中，如果横坐标比x大，或者纵坐标比y大，则可以认为是无效的障碍物。（好像有些样例就是需要这点）
- 2.只记录第一个周期内经历过的坐标为`First[][]`：如果执行了command的第i个指令后，机器人的坐标为`(cur_x,cur_y)`，那么有`First[i]={cur_x,cur_y}`，其中i=0,1,...,command.length()-1。最后用DX和DY记录从(0,0)开始，经历了一个command周期后的横坐标与纵坐标。
- 3.对于某个有效的obstacle（这点由1判断），其坐标为(obx,oby)这样判断它是否在机器人路径上：如果对每一个i(i=0,1,...,command.length()-1)，都有$斜率k1=\frac{oby-First[i][1]}{obx-First[i][0]} \not= \frac{DY}{DX} = 斜率k2$，那么这个obstacle就不在机器人的路径上。对每一个有效障碍物检验这一点，如果有一个没有满足，就return false。为了不出现小数，检验式应当化为乘积形式：$DY \times (obx-First[i][0]) \not= DX \times (oby-First[i][1])$
- 4.对于终点(x,y)同样可以用3的判断方法。

### 代码

```java
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int[][] first = new int[command.length()][2];
        int l = command.length();
        int DX = 0;
        int DY = 0;
        for(int i=0;i<l;i++){
            first[i][0] = DX;
            first[i][1] = DY;
            char com = command.charAt(i);
            if(com=='R')DX++;
            else DY++;
        }
        //(ob[0]-f[0])/(ob[1]-f[1]) = DX/DY
        for(int[] ob:obstacles){
            if(ob[0]==x&&ob[1]==y)return false;
            if(ob[0]>x||ob[1]>y)continue;
            for(int i=0;i<l;i++){
                int k1 = DX * (ob[1]-first[i][1]);
                int k2 = DY * (ob[0]-first[i][0]);
                if(k1==k2)return false;
            }
        }
        for(int i=0;i<l;i++){
            int k1 = DX * (y-first[i][1]);
            int k2 = DY * (x-first[i][0]);
            if(k1==k2)return true;
        }
        return false;
    }
}
```