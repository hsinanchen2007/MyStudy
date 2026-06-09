最开始的算法，很简单，就是模拟机器人一步一步走，一边走一边判断，是否装上障碍物或者到达目的地。
做了一些小优化，比如，把障碍数组进行排序，避免每次判断是否碰撞都遍历一次障碍数组。
提交后的结果差不多是600ms。

虽然这个算法很简单，但是，如果 obstacles足够大，沿着路径足够集中，command足够大，这个算法的效率也不算太差

但是，在题目给出的测试用例中，obstacles长度小于1000，command也不大，所以，完全没必须实际走路径，只要判断障碍点和目标是否在路径上就行了，但是，每次判断是否在路径上（inRoute方法），如果都遍历command，就会变成O(m*n)

在inRoute()中，在判断x是第几组command，第几个R后，就要找出这个R后面有几个U，又变成了遍历command
专门做了一个数据结构，记录了一个command中，每个R对应U的范围，比如，"RRUURUUU"，数组int[][] x_y的内容就是：
{{0,0},{0,0}{0,2}{2,5}}，也就是第0个R的U值范围是0-0，第1个 0-0，第2个0-2，第三个2-5。

通过这个数据结构，就能通过查表的方式，迅速判断，R对应的U的范围，整个算法的复杂度就变成了O(m+n)

最终的运行时间是1ms

java版代码
```
class Solution {

    
    public boolean robot(String command, int[][] obstacles, int x, int y) {

        countCommand(command);

        if(inRoute(x,y)==false)return false;

        for(int[] coord : obstacles){
            int curX=coord[0];
            int curY=coord[1];
            if(curX>x || curY>y)continue;

            if (inRoute(curX, curY )) return false;

        }
        return true;
    }

    private boolean inRoute(int obtX, int obtY) {

        int groupIndex=obtX / countR;
        if(obtX%countR ==0)groupIndex-=1;

        int currentX=groupIndex*countR;
        int currentY=groupIndex*countU;

        int deltaY=obtY-currentY;
        int[] tempArr=x_y[obtX-currentX];
        if(tempArr[0]<=deltaY&&deltaY<=tempArr[1]) return true;
        return false;
    }

    int countU=0;
    int countR=0;
    public int[][] x_y;
    private void countCommand(String Command){
        for(char ch : Command.toCharArray()){
            if(ch=='U')countU+=1;
            else countR+=1;
        }
        x_y=new int[countR+1][2];
        int currentX=0;
        int currentY=0;
        for(char ch : Command.toCharArray()){
            if(ch=='U'){
                currentY+=1;
                x_y[currentX][1]=currentY;

            }
            else {
                currentX+=1;
                x_y[currentX][0]=currentY;
                x_y[currentX][1]=currentY;
            }
        }
        x_y[x_y.length-1][1]+=x_y[0][1];
    }
}
```
