### 解题思路
我用字符串的方式记录并判断是否是障碍的时候，系统提示超时。
//我的方法
ArrayList<String> allobstacles = new ArrayList<>();
for (int[] obstacle: obstacles) 
{
        String str = String.valueOf(obstacle[0]) + "," +  String.valueOf(obstacle[1])+ ",";
        allobstacles.add(str);
}

看了官方文档，用下面的方式替代
Set<Long> obstacleSet = new HashSet();
for (int[] obstacle: obstacles) 
{
    long ox = (long) obstacle[0] + 30000;
    long oy = (long) obstacle[1] + 30000;
    obstacleSet.add((ox << 16) + oy);
}


### 代码

```java
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[] dx = new int[]{0, 1, 0, -1};
        int[] dy = new int[]{1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        Set<Long> obstacleSet = new HashSet();
        for (int[] obstacle: obstacles) {
            long ox = (long) obstacle[0] + 30000;
            long oy = (long) obstacle[1] + 30000;
            obstacleSet.add((ox << 16) + oy);
        }
        
        int ans = 0;
        for (int cmd: commands) {
            if (cmd == -2)  //left
                di = (di + 3) % 4;
            else if (cmd == -1)  //right
                di = (di + 1) % 4;
            else 
            {
                for (int k = 0; k < cmd; ++k) 
                {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    long code = (((long) nx + 30000) << 16) + ((long) ny + 30000);
                    if (!obstacleSet.contains(code))  
                    {
                        x = nx;
                        y = ny;
                        ans = Math.max(ans, x*x + y*y);
                    }
                }
            }
        }

        return ans;
    }
}
```