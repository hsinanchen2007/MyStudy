![1.png](https://pic.leetcode-cn.com/20086db12c310b0f5e88fb5b80b8b682c77d935200c538dab370400578440591-1.png)

# 分步骤实现，1.不触碰障碍点，2.能抵达终点
首先，需要一个按路径行走判断是否能到达点的方法
  1.判断能否到达点，只有UR上右，单次行走一步，那么抵达点A(x,y)，机器人行走了x+y步，也就是执行了x+y次移动指令
  故方法如下：
    测试中遇见的问题：1.可能没有障碍点，2.可能障碍点在起终点形成的矩形外，3.按指令终点不可达

```
    public boolean getCount(int x, int y, String command) {
        for(;command.length()<x+y;){
            command +=command;
        }
        int[] yxStep = getDirectionCount(command, x+y);
        return y == yxStep[0] && x == yxStep[1];
    }

    //获取执行指令中UR的个数
    public int[] getDirectionCount(String command, int length) {
        int[] count = new int[]{0, 0};
        char[] charArr = command.toCharArray();
        for (int i = 0; i < length; i++) {
            if (charArr[i] == 'U') {
                count[0]++;
            } else {
                count[1]++;
            }
        }
        return count;
    }

    //方法如上，但是提交后，会涉及到内存溢出，原因是有的x+y非常大，导致command拼接的次数相当巨大，所以优化也在command拼接那里优化
    //优化后通过command的长度来获取移动指令中UR的次数
    public boolean getCount(int x, int y, String command) {
        int times = (x + y) / command.length();
        int extra = (x + y) % command.length();
        int[] yxStep = getDirectionCount(command, command.length());
        int[] yxStepEx = getDirectionCount(command, extra);
        yxStep[0] = yxStep[0] * times + yxStepEx[0];
        yxStep[1] = yxStep[1] * times + yxStepEx[1];
        return y == yxStep[0] && x == yxStep[1];
    }

    //补全：开始方法
    public static boolean robot(String command, int[][] obstacles, int x, int y) {
        for (int[] point : obstacles) {
            int pX = point[0];
            int pY = point[1];
            if (pX + pY > x + y) { //障碍点不在起终点的范围内
                continue;
            }
            if (getCount(pX, pY, command)) { //经过障碍点
                return false;
            }
        }
        return getCount(x, y, command);//经过终点

    }
```