### 解题思路
刚开始以为这题很简单，结果写了之后才发现主要难度在于测试案例，要考虑时间复杂度
第一遍的代码没有考虑任何边界，直接超时了，于是加上了先求出obstacles数组中的最大x和y，一旦当前路径超过这个范围就不再遍历obstacles数组判断
第二遍的代码还是没过，显示仍然超时，发现还存在一个最小x和y的判断，如果当前路径不小于这个最小x或者y，则不开始遍历obstacles数组判断。
第三遍就过了。
思路比较复杂，不能和大佬们比，撒花。

### 代码

```java
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int position_x = 0;
        int position_y = 0;
        int obstacles_max_x = 0;
        int obstacles_max_y = 0;
        //首先求出obstacels数组中最大的x和y，以简化判断条件，只要超出这个x和y的范围，就不再判断力
        for (int m = 0; m < obstacles.length; m++){
            if (obstacles[m][0] > obstacles_max_x){
                obstacles_max_x = obstacles[m][0];
            }
            if (obstacles[m][1] > obstacles_max_y){
                obstacles_max_y = obstacles[m][1];
            }
        }
        int obstacles_min_x = obstacles_max_x;
        int obstacles_min_y = obstacles_max_y;
        for (int m = 0; m < obstacles.length; m++){
            if (obstacles[m][0] < obstacles_min_x){
                obstacles_min_x = obstacles[m][0];
            }
            if (obstacles[m][1] < obstacles_min_y){
                obstacles_min_y = obstacles[m][1];
            }
        }
        //超出边界则不再循环
        while (!(position_x > x || position_y > y)){
            for(int i = 0; i < command.length(); i++){
                if (command.charAt(i) == ('U')){
                    position_y++;
                }else if (command.charAt(i) == ('R')){
                    position_x++;
                }
                if (position_x > x || position_y > y){
                    return false;
                }
                if (position_x == x && position_y == y){
                    return true;
                }
                if (!(position_x > obstacles_max_x|| position_y > obstacles_max_y)
                && (position_x >= obstacles_min_x || position_y >= obstacles_min_y)){
                    for (int m = 0; m < obstacles.length; m++){
                        if (position_x == obstacles[m][0] && position_y == obstacles[m][1]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}
```