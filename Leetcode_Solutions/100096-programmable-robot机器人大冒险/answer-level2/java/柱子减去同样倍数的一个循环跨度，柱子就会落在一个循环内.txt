


```
class Solution {
    /**
    * 1.找出一个循环
      2.判断能否到终点
            终点值想x,y 减去同样倍数的r,u 使结果x落在循环内 x%r, (y-u*(x/r));
            判断是否与循环内的路径碰撞，碰撞则能到达终端
      3.同理，判断柱子是否碰撞，碰撞则false
    */
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        char[] chars = command.toCharArray();
        int r=0, u=0;
        //一个循环
        int[][] targets = new int[chars.length+1][2];
        int i=0;
        for(char c : chars){
            if(c=='U'){
                u++;
            }else{
                r++;
            }
            targets[++i]=new int[]{r,u};
        }

        //hash化便于查找
        Set<String> set = new HashSet();
        for( i=0;i<targets.length;i++){
            set.add(targets[i][0] + "," + targets[i][1]);
        }

        //判断能否到达
        String t = x%r +"," + (y-u*(x/r));
        if(!set.contains(t)){
            return false;
        }

        //遍历柱子，判断是否碰撞
        for(int[] obstac : obstacles){
            if(obstac[0]>x || obstac[1]>y){
                continue;
            }
            int m = obstac[0]/r;
            int nr = obstac[0]%r;
            int nu = obstac[1]-m*u;
            String target = nr + "," + nu;
            //是否在路径上
            if(set.contains(target)){
                return false;
            }
        }
        return true;
    }
}
```
