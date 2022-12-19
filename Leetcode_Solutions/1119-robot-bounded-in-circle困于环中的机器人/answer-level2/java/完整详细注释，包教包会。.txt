```
class Solution {
    public boolean isRobotBounded(String instructions) {
        int i = 0,j=0;//向东向北增加，向西向南减少
        int t=0,len=instructions.length();
        int dir=0;//前进方向，开始假设朝东
        int[][] d = {{3,2},{2,3},{0,1},{1,0}};//状态机,行代表0东1西2南3北，列代表0左1右，例如东左转就是北
        while(t<len){
           switch(instructions.charAt(t%len)){
               case 'G':
                   if(dir==0)i++;
                       else if(dir==1)i--;
                           else if(dir==2)j++;
                               else j--;
                   break;
               case 'L':
                   dir=d[dir][0];//根据状态机改变方向
                   break;
               case 'R':
                   dir=d[dir][1];
                   break;
           }
          t++;   
        }
        if((i==0&&j==0)||dir!=0)return true;//循环一次若是回到终点或者方向改变就可以
        return false;
    }
}
```
