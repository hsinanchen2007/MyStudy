1. 先对保存障碍物坐标的二维数组进行处理，其中横坐标和纵坐标均小于目标坐标的那些坐标点才是我们需要考虑的，因为超出的坐标是不会损坏机器人的。将满足的那些坐标保存在二维数组的前 $index$ 位。
2. 对指令 `command` 进行 `while` 循环，直到机器人所在位置已经超过目标坐标时才跳出循环。
3. 在循环内，每次行走一步后都需要判断一下是否到达目标点和是否触碰到障碍物。对障碍物数组循环时只需要从 $0$ 到 $index$ 即可，可以减小时间开销。
4. 结果：![image.png](https://pic.leetcode-cn.com/9c24b8320a43bb957cb3ef433a440e62306045eae7294e71b20205c4831da88a-image.png){:width=350}
```java [-Java]
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
      int[] location = new int[2];
        int i = 0;
        int index =0;
        for(int m=0;m<obstacles.length;m++)
        {
            if(obstacles[m][0]<=x&&obstacles[m][1]<=y)
            {
                obstacles[index][0]=obstacles[m][0];
                obstacles[index++][1]=obstacles[m][1];
            }
        }
        while (location[0] <= x && location[1] <= y) {
            if (i == command.length()) {
                i = 0;
            }
            if (command.substring(i, i + 1).equals("U")) {
                location[1] = location[1] + 1;
            } else {
                location[0] = location[0] + 1;
            }
            if (location[0] == x && location[1] == y) {
                return true;
            }
            for (int m = 0; m < index; m++) {
                if (location[0] == obstacles[m][0] && location[1] == obstacles[m][1]) {
                    return false;
                }
            }
            i++;
        }
        return false;
    }
}
```