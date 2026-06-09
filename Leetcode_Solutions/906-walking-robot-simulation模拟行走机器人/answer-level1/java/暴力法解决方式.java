逻辑繁琐,运行时间也不太好，但毕竟是自己想出来的，分享一下有兴趣的可以看一下。主要思路是假设机器人前进的每一步都不会遇到障碍，预先计算出机器人将要到达的目标点，通过分析目标点与上一个点的位置，遍历数组，寻找是否存在障碍，若存在障碍则记录障碍位置，在遇到多个障碍时只取最近的障碍。再吐槽一下，这题算简单题过分了喂！掉头发



 public int robotSim(int[] commands, int[][] obstacles) {
```
代码块
```
        /*
         * -2：向左转 90 度
         * -1：向右转 90 度
         * 1 <= x <= 9：向前移动 x 个单位长度
         */
        int x = 0;//机器人的初始x轴位置
        int y = 0;//机器人的初始y轴位置
        int way = 0;//机器人前进方向,初始为北
        int temp = 0;//判断是否发生碰撞
        int max = 0;//记录最大欧式距离
        for (int i = 0; i < commands.length; i++) {
            if (commands[i] == -2 || commands[i] == -1) {//转向
                way = getWay(way, commands[i]);
            } else {//向前进
                switch (way) {
                    case 0:
                        temp = judgeCollide(x, y, x , y+ commands[i], obstacles);//判断碰撞
                        if (temp != 0) {
                            y += temp-1;
                        } else {
                            y += commands[i];
                        }
                        max = Math.max(max, x*x + y*y);
                        break;
                    case 1:
                        temp = judgeCollide(x, y, x+commands[i], y, obstacles);
                        if (temp != 0) {
                            x += temp-1;
                        } else {
                            x += commands[i];
                        }
                        max = Math.max(max, x*x + y*y);
                        break;
                    case 2:
                        temp = judgeCollide(x, y, x, y-commands[i], obstacles);
                        if (temp != 0) {
                            y -= temp-1;
                        } else {
                            y -= commands[i];
                        }
                        max = Math.max(max, x*x + y*y);
                        break;
                    case 3:
                        temp = judgeCollide(x, y, x-commands[i], y, obstacles);
                        if (temp != 0) {
                            x -= temp-1;
                        } else {
                            x -= commands[i];
                        }
                        max = Math.max(max, x*x + y*y);
                        break;
                }
            }
        }
        return  max;
    }

    /**
     * 获取机器人前进方向
     *
     * @param way
     * @return 前进方向
     * 0 北
     * 1 东
     * 2 南
     * 3 西
     */
    public int getWay(int way, int turnWay) {
        if (turnWay == -2) {//-2：向左转 90 度
            if (way == 0) {
                way = 3;
            } else {
                way -= 1;
            }
        } else {//-1 向右转 90 度
            if (way == 3) {
                way = 0;
            } else {
                way += 1;
            }
        }
        return way;
    }

    /**
     * 判断是否反是碰撞
     *
     * @param x         机器人初始x轴坐标
     * @param y         机器人初始y轴坐标
     * @param x1        机器人移动后x轴坐标
     * @param y1        机器人移动后y轴坐标
     * @param obstacles 可能碰撞点
     * @return 0/distance 0表示无碰撞，distance表示在此距离上+1则会发生碰撞
     *
     */
    public int judgeCollide(int x, int y, int x1, int y1, int[][] obstacles) {
        if(obstacles == null){
            return 0;
        }
        int distance = 0;//记录碰撞位置
        int temp = 0;//判断是否产生多次碰撞
        for (int i=0;i<obstacles.length;i++){//遍历障碍数组判断是否存在碰撞点
            if(x == x1 && obstacles[i][0] == x){//在y轴碰撞，x轴值相同
                if(Math.min(y,y1)<=obstacles[i][1] && obstacles[i][1]<=Math.max(y,y1)){//若在y轴距离上碰撞
                    if( temp == 0){
                        distance = Math.abs(obstacles[i][1] - y);
                        temp++;
                    }else{//当预计发生多次碰撞，只选择最近碰撞点
                        distance = Math.min(Math.abs(obstacles[i][1] - y),distance);
                    }
                }
            }else if(y == y1 && obstacles[i][1] == y){//在x轴碰撞，y轴值相同
                if(Math.min(x,x1)<=obstacles[i][0] && obstacles[i][0]<=Math.max(x,x1)){
                    if(temp == 0){
                        distance =Math.abs(obstacles[i][0] - x);
                        temp++;
                    }else{
                        distance = Math.min(Math.abs(obstacles[i][0] - x),distance);
                    }
                }
            }

        }
        return distance;
    }