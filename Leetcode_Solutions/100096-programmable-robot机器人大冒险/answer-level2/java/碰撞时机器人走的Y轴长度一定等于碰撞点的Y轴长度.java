思路：首先 机器路径肯定是可以无限长的 但是最多结束到 的位置是 假定机器人走的路长为L(U+R) 时结束
那么 程序停止的时候一定是2种情况  所有碰撞节点的长度和大于终点点可以全部排除在外
 1，false L=obstacles[x][0]+obstacles[x][1] ,且 LU= obstacles[x][1]

 2，true  L=X+Y     且  LU=Y

 3 false  1和2都不满足
```
  public boolean robot(String command, int[][] obstacles, int x, int y) {
                char[] urls = command.toCharArray();
        int countY = 0;
        int[] countU = new int[urls.length];
        for (int i = 0; i < urls.length; i++) {
            countU[i] = 'U' == urls[i] ? ++countY : countY;
        }
        int l = 0;
        int mod = 0;
        for (int[] ints : obstacles) {
            if ((ints[0] + ints[1]) > (x + y))
                continue;
            l = (ints[0] + ints[1]) / urls.length;
            mod = (ints[0] + ints[1]) % urls.length;
            mod--;
            if (mod >= 0){
                if (countU[mod] + l * countU[urls.length - 1] == ints[1])
                    return false;
            } else if (l * countU[urls.length - 1] == ints[1])
                    return false;
        }
         //将终点作为一个碰撞点检查一次
        l = (x + y) / urls.length;
        mod = (x + y) % urls.length;
        mod--;
        if (mod >= 0){
            if (countU[mod] + l * countU[urls.length - 1] == y)
                return true;
        } else if (l * countU[urls.length - 1] == y)
                return true;

        return false;
    }
```
![image.png](https://pic.leetcode-cn.com/35825fde918da3e37395d54c495a904f3f8d156fcf74ab5b55901dee30cb89c1-image.png)


 

 
 
 